#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,P=131;
typedef unsigned long long ull;
ull p[N];
string s1,s2,t1,t2;
ull H(string s,int l,int r){
	ull res=0;
	for(int i=r;i>=l;i--)
		res=res*P+(s[i]-'a'+1);
	return res;
}
int tr[N][729],pre[N];
void dfs(int u){
	for(int i=0;i<729;i++){
		int v=tr[u][i];
		if(v){
			pre[v]+=pre[u];
			dfs(v);
		}
	}
}
int n,q,idx;
map<ull,int> rt;
int lst[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<N;i++)p[i]=p[i-1]*P;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int l=1e9,r=-1,m=s1.size();
		for(int j=0;j<m;j++)
			if(s1[j]!=s2[j]){
				l=j;break;
			}
		if(l==1e9)continue;
		for(int j=m-1;j>=0;j--)
			if(s1[j]!=s2[j]){
				r=j;break;
			}
		ull h=H(s1,l,r)*p[r-l+1]+H(s2,l,r);
		if(rt.count(h)==0){
			rt[h]=++idx;
			lst[++lst[0]]=idx;
		}
		int cur=rt[h];
		for(int j=1;;j++){
			int dir=0;
			if(l-j<0&&r+j>=m)break;
			if(l-j>=0)dir=27*(s1[l-j]-'a'+1);
			if(r+j<m)dir+=(s1[r+j]-'a'+1);
			if(tr[cur][dir]==0)tr[cur][dir]=++idx;
			cur=tr[cur][dir];
		}
		pre[cur]++;
	}
	for(int i=1;i<=lst[0];i++)dfs(lst[i]);
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int l,r=-1,m=s1.size();
		for(int j=0;j<m;j++)
			if(s1[j]!=s2[j]){
				l=j;break;
			}
//		if(l==m)continue;
		for(int j=m-1;j>=0;j--)
			if(s1[j]!=s2[j]){
				r=j;break;
			}
		ull h=H(s1,l,r)*p[r-l+1]+H(s2,l,r);
		if(rt.count(h)==0){
			cout<<0<<endl;
			continue;
		}
		int cur=rt[h];
		for(int j=1;;j++){
			int dir=0;
			if(l-j<0&&r+j>=m)break;
			if(l-j>=0)dir=27*(s1[l-j]-'a'+1);
			if(r+j<m)dir+=(s1[r+j]-'a'+1);
			if(tr[cur][dir]==0)break;
			cur=tr[cur][dir];
		}
		cout<<pre[cur]<<endl;
	}
}
