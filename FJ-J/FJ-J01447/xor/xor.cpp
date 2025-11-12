#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
struct node{
	int x,y;
};
int n,k,cnt,ans;
int a,s[maxn];
bool vis[maxn];
vector<int> g[maxn];
void fopen(int l,int r){
	for(int i=l;i<=r;i++)
		vis[i]=1;
}
void fclose(int l,int r){
	for(int i=l;i<=r;i++)
		vis[i]=0;
}
void dfs(int l,int now){
	if(now>ans) ans=now;
	for(int i=0;i<g[l].size();i++){
		int r=g[l][i];
		fopen(l,r);
		dfs(r+1,now+1);
		fclose(l,r);
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=a^s[i-1];
		//cout<<s[i]<<' ';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((s[j-1]^s[i])==k) 
				g[j].push_back(i);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<g[i].size();j++)
//			cout<<i<<' '<<g[i][j]<<endl;
//	}
	int aa=1,mx=-1;
	while(!g[aa].size()) aa++;
	for(int i=0;i<g[aa].size();i++){
		if(g[aa][i]>mx)
			mx=g[aa][i];
	}
	//cout<<mx;
	for(int i=1;i<=mx;i++) dfs(i,0);
	cout<<ans;		
}
//5 1
//1 4 3 2 3
