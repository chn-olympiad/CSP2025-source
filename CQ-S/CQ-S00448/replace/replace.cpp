#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=10000139;
//struct node{
//	ull ha;
//	int id;
//	node(){
//		
//	}
//	node(ull a,int b){
//		ha=a;
//		id=b;
//	}
//}ndi[5000010];
//int tot;
int hd[N],k2[5000010],ne[5000010],c1;
ull k1[5000010];
const int bs=1201;
int n,q;
string s[200010][2];
map<int,int>son[5000010];
int cnt[5000010];
int sum[5000010];
ull	ha[5000010];
ull P[5000010];
int idx=1;
int test_m;
void insert(ull a1,int a2){
	int x=a1%N;
	c1++;
	k1[c1]=a1;
	k2[c1]=a2;
	ne[c1]=hd[x];
	hd[x]=c1;
}
int getu(ull x){
	int C=0;
	int id=x%N;
	for(int i=hd[id];i;i=ne[i]){
		C++;
		test_m=max(test_m,C);
		if(k1[i]==x){
			return k2[i];
		}
	}
	return -1;
}
int mkp(int x,int y){
	return x*26+y+1;
}
void insert(string&s1,string&s2){
	int p=1;
	//sum[1]++;
	for(int i=0;i<s1.length();i++){
		int t=mkp(s1[i]-'a',s2[i]-'a');
		if(!son[p].count(t)){
			son[p][t]=++idx;
		}
		p=son[p][t];
		//sum[p]++;
	}
	cnt[p]++;
}
void dfs(int u,ull h){
	if(u==1){
		sum[u]=cnt[u];
	}
	insert(h,u);
	//ndi[++tot]=node(h,u);
	for(auto tmp:son[u]){
		int t=tmp.first,v=tmp.second;
		sum[v]=sum[u]+cnt[v];
		dfs(v,h*bs+t);
	}
}
//bool cmp(node a,node b){
//	return a.ha<b.ha;
//}
//int getu(ull x){
//	int l=1,r=tot,mid;
//	while(l<r){
//		mid=(l+r)>>1;
//		if(ndi[mid].ha>=x)r=mid;
//		else l=mid+1;
//	}
//	if(ndi[l].ha==x)return ndi[l].id;
//	return -1;
//}
ll getha(int l,int r){
	return ha[r]-ha[l-1]*P[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	P[0]=1;
	for(int i=1;i<=5000000;i++){
		P[i]=P[i-1]*bs;
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		insert(s[i][0],s[i][1]);
	}
	dfs(1,0);
	//sort(ndi+1,ndi+tot+1,cmp);
	//int slen=0;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.length();
		//slen+=len+t2.length();
		if(t2.length()!=len){
			cout<<0<<"\n";
			continue;
		}
		t1=" "+t1;
		t2=" "+t2;
		for(int i=1;i<=len;i++){
			ha[i]=ha[i-1]*bs+mkp(t1[i]-'a',t2[i]-'a');
		}
		int l,r;
		for(int i=1;i<=len;i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=len;i>=1;i--){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		ll res=0;
		for(int i=l;i>=1;i--){
			int u=getu(getha(i,r));
			if(u==-1)continue;
			int li=r,ri=len,mid;
			while(li<ri){
				mid=(li+ri+1)>>1;
				if(getu(getha(i,mid))!=-1)li=mid;
				else ri=mid-1;
			}
			//cerr<<t1<<" "<<t2<<endl;
			//cerr<<"li:"<<i<<" "<<li<<endl;
			res+=sum[getu(getha(i,li))];
			//cerr<<res<<endl;
			res-=sum[u];
			//cerr<<res<<endl;
			res+=cnt[u];
			//cerr<<res<<endl;
		}
		cout<<res<<"\n";
	}
	//cerr<<slen<<endl;
	//cerr<<test_m<<endl;
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
