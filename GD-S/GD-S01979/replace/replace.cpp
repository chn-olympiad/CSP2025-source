#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ul;
const int M=5000005;
const int bl=317;
ul hp[5000010];
const ul p1=998244353,p2=1e9+7;
struct nd{
	string c;
	vector<ul> hs,ds;
	int n;
	void gen(){
		n=c.length();
		c=" "+c;
		hs.resize(n+2,0);
		ds.resize(n+2,0);
		for(int i=1;i<=n;i++){
			hs[i]=hs[i-1]+hp[i]*c[i];
		}
		for(int i=n;i>=1;i--){
			ds[i]=ds[i+1]+hp[M-i]*c[i];
		}
	}
}s[100010][2],s1,s2;
ul get_hs(nd &g,int x,int y){
	return (g.hs[y]-g.hs[x-1])*hp[M-y];
}
ul get_ds(nd &g,int x,int y){
	return (g.ds[x]-g.ds[y+1])*hp[x];
}
int get_fr(nd &a,nd &b){
	int le=0,ri=a.n,mid;
	while(le<ri){
		mid=(le+ri+1)>>1;
//		cout<<a.c<<b.c<<" "<<1<<" "<<mid<<" "<<get_hs(a,1,mid)<<" "<<get_hs(b,1,mid)<<"\n";
		if(get_hs(a,1,mid)==get_hs(b,1,mid)){
			le=mid;
		}
		else{
			ri=mid-1;
		}
	}
	return le;
}
int get_bk(nd &a,nd &b){
	int len=a.n;
	int le=0,ri=len,mid;
	while(le<ri){
		mid=(le+ri+1)>>1;
		if(get_hs(a,len-mid+1,len)==get_hs(b,len-mid+1,len)){
			le=mid;
		}
		else{
			ri=mid-1;
		}
	}
	return len-le+1;
}
int n,q;
ul a[100010],b[100010],c[100010];
int l[100010],r[100010];
unordered_map<ul,vector<ul>> ta,tb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	hp[0]=1;
	hp[1]=13131;
	for(int i=2;i<=5000005;i++){
		hp[i]=hp[i-1]*hp[1];
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0].c>>s[i][1].c;
		if(s[i][0].c==s[i][1].c) continue;
		s[i][0].gen();
		s[i][1].gen();
		l[i]=get_fr(s[i][0],s[i][1]);
		r[i]=get_bk(s[i][0],s[i][1]);
		a[i]=get_ds(s[i][0],1,l[i]);
		b[i]=get_hs(s[i][0],r[i],s[i][0].n);
		c[i]=get_hs(s[i][0],l[i]+1,r[i]-1)*p1+get_hs(s[i][1],l[i]+1,r[i]-1)*p2;
		a[i]^=c[i],b[i]^=c[i];
		ta[a[i]].push_back(b[i]);
//		cerr<<l[i]<<" "<<r[i]<<" "<<a[i]<<" "<<b[i]<<"\n";
	}
	for(int i=1;i<=n;i++){
		if(s[i][0].c==s[i][1].c) continue;
		if(ta[a[i]].size()>bl) tb[b[i]].push_back(a[i]);
	}
	vector<ul> tl,tr;
	unordered_map<ul,int> ml,mr;
	while(q--){
		s1=nd();
		s2=nd();
		cin>>s1.c>>s2.c;
		if(s1.c.length()!=s2.c.length()){
			cout<<0<<"\n";
			continue;
		}
		s1.gen();
		s2.gen();
		int len=s1.n;
		int ll=get_fr(s1,s2);
		int rr=get_bk(s1,s2);
		ul cc=get_hs(s1,ll+1,rr-1)*p1+get_hs(s2,ll+1,rr-1)*p2;
		int ans=0;
		unordered_map<ul,int>().swap(ml);
		unordered_map<ul,int>().swap(mr);
		ml[cc]++;
		mr[cc]++;
//		cerr<<1<<" "<<ll<<" "<<rr<<" "<<len<<"\n";
		for(int j=ll;j>=1;j--){
			ul w=get_ds(s1,j,ll);
			w^=cc;
			ml[w]++;
		}
		for(int j=rr;j<=len;j++){
			ul w=get_hs(s1,rr,j);
			w^=cc;
			mr[w]++;
		}
		for(auto tp:ml){
			ul w=tp.first;
			int cnt=tp.second;
//			cerr<<"ml:"<<w<<" "<<cnt<<"\n";
			if(ta[w].size()<=bl){
				for(ul j:ta[w]){
//					cerr<<w<<" "<<j<<"\n";
					ans+=cnt*mr[j];
				}
			}
		}
		for(auto tp:mr){
			ul w=tp.first;
			int cnt=tp.second;
//			cerr<<"mr:"<<w<<" "<<cnt<<"\n";
			for(ul j:tb[w]){
//				cerr<<w<<" "<<j<<"\n";
				ans+=cnt*ml[j];
			}
		}
		cout<<ans<<"\n";
	}
}
