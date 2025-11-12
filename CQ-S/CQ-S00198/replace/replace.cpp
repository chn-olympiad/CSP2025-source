#include<bits/stdc++.h>
#define pl tuple<int,int,int,int>
#define mod 998244353
#define ll long long
using namespace std;

const int N=4e5+5,M=5e6+5;
int n,m,idx,ans[N],num[M];
int root,cnt,tot,son[M][30],in[M],out[M];
struct nnd {
	int l1,r1,l2,r2;
	string sl,sr;
}A[N];
struct mmb {
	int x,y;
	string sl,sr;
}B[N];
unordered_map<ll,int>mp;
vector<int>dot[N][2];
vector<pl>gg;
void add(int x,int w){
	for(int i=x;i<M;i+=(i&-i))
		num[i]+=w;
}
int get(int x){
	int ans=0;
	for(int i=x;i;i-=(i&-i))
		ans+=num[i];
	return ans; 
}
void cl(int x){
	for(int i=0;i<26;i++)
		son[x][i]=in[x]=out[i]=0;
}
int ins(string s){
	int x=root,len=s.size();
	for(int i=0;i<len;i++){
		if(!son[x][s[i]-'a'])
			son[x][s[i]-'a']=++cnt,cl(cnt);
		x=son[x][s[i]-'a'];
	}
	return x;
}
int find(string s){
	int x=root,len=s.size();
	for(int i=0;i<len;i++){
		if(!son[x][s[i]-'a'])
			return 0;
		x=son[x][s[i]-'a'];
	}
	return in[x];
}
void dfs(int x){
	in[x]=++tot;
	for(int j=0;j<26;j++)
		if(son[x][j])
			dfs(son[x][j]);
	out[x]=tot;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1,l,r;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1==s2)
			continue;
		l=1,r=s1.size();
		s1=' '+s1,s2=' '+s2;
		while(s1[l]==s2[l])l++;
		while(s1[r]==s2[r])r--;
		for(int j=l-1;j>0;j--)
			A[i].sl+=(char)s1[j];
		for(int j=r+1;j<s1.size();j++)
			A[i].sr+=(char)s1[j];
		ll sum=0;
		for(int j=l;j<=r;j++)
			sum=(sum*26+s1[j]-'a')%mod;
		for(int j=l;j<=r;j++)
			sum=(sum*26+s2[j]-'a')%mod;
		if(!mp[sum])mp[sum]=++idx;
		dot[mp[sum]][0].push_back(i);
//		cerr<<"			"<<i<<" "<<mp[sum]<<"\n";
//		cerr<<s1<<" "<<s2<<"\n";
//		cerr<<"	"<<A[i].sl<<" "<<A[i].sr<<"\n";
	}
//	cerr<<"---\n";
	for(int i=1,l,r;i<=m;i++){
		string s1,s2;
		cin>>s1>>s2;
		l=1,r=s1.size();
		s1=' '+s1,s2=' '+s2;
		while(s1[l]==s2[l])l++;
		while(s1[r]==s2[r])r--;
		for(int j=l-1;j>0;j--)
			B[i].sl+=(char)s1[j];
		for(int j=r+1;j<s1.size();j++)
			B[i].sr+=(char)s1[j];
		ll sum=0;
		for(int j=l;j<=r;j++)
			sum=(sum*26+s1[j]-'a')%mod;
		for(int j=l;j<=r;j++)
			sum=(sum*26+s2[j]-'a')%mod;
		
//		if(i==142){
//			cerr<<mp[sum]<<"\n"<<s1<<"\n"<<s2<<"\n"<<(s1==s2)<<"\n";
//			for(int j=l;j<=r;j++)
//				cerr<<s1[j];
//			cerr<<"\n";
//			for(int j=l;j<=r;j++)
//				cerr<<s2[j];
//			cerr<<"\n";
//		}
		if(!mp[sum])continue;
		dot[mp[sum]][1].push_back(i);
//		cerr<<"			"<<i<<" "<<mp[sum]<<"\n";
//		cerr<<s1<<" "<<s2<<"\n";
//		cerr<<"	"<<B[i].sl<<" "<<B[i].sr<<"\n";
	}
//	cerr<<"---\n";
	for(int t=1;t<=idx;t++){
		gg.clear();
		root=cnt=1,tot=0,cl(root);
		for(int it:dot[t][0]){
			A[it].l1=ins(A[it].sl);
		}
		dfs(root);
//		cerr<<cnt<<" "<<tot<<"\n";
		for(int it:dot[t][0]){
			int x=A[it].l1;
//			cerr<<it<<" -"<<A[it].sl<<"- "<<x<<" "<<in[x]<<" "<<out[x]<<"   ";
			A[it].l1=in[x],A[it].r1=out[x];
		}
//		cerr<<"\n";
		for(int it:dot[t][1]){
			B[it].x=find(B[it].sl);
//			cerr<<it<<" -"<<B[it].sl<<"- "<<B[it].x<<"\n";
		}
//		cerr<<"\n";

		root=cnt=1,tot=0,cl(root);
		for(int it:dot[t][0])
			A[it].l2=ins(A[it].sr);
		dfs(root);
//		cerr<<tot<<"\n";
		for(int it:dot[t][0]){
			int x=A[it].l2;
			A[it].l2=in[x],A[it].r2=out[x];
//			cerr<<it<<":\n";
//			cerr<<"	"<<A[it].l1<<" "<<A[it].r1<<" "<<A[it].l2<<" "<<A[it].r2<<"\n";
			gg.push_back(pl(A[it].l1,1,A[it].l2,A[it].r2));
			gg.push_back(pl(A[it].r1+1,-1,A[it].l2,A[it].r2));
		}
		for(int it:dot[t][1]){
			B[it].y=find(B[it].sr);
			if(!B[it].x||!B[it].y)continue;
//			cerr<<it<<":\n";
//			cerr<<"	"<<B[it].x<<" "<<B[it].y<<"\n";
			gg.push_back(pl(B[it].x,2,B[it].y,it));
		}
		sort(gg.begin(),gg.end());
		for(pl it:gg){
			if(get<1>(it)==2){
				int x=get<2>(it),id=get<3>(it);
//				cerr<<B[id].x<<" "<<x<<" "<<id<<" "<<get(x)<<"\n";
				ans[id]=get(x);
			} else {
				int x=get<2>(it),y=get<3>(it),w=get<1>(it);
				add(x,w),add(y+1,-w);
//				cerr<<"	"<<x<<" "<<y<<" "<<w<<"\n";
			}
		}
		gg.clear();
//		cerr<<"----\n";
	}
//	cerr<<"---\n";
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<"\n";
//		cerr<<ans[i]<<"\n";
	}
	
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
