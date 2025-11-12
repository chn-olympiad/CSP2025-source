#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N=505,mod=998244353; 

int n,m,ans;
string s;
int a[N],ap[N];
bool vis[N];

void dfs(int id/*,int sum*/){
	if(id==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(i-1-sum>=a[ap[i]])continue;
			if(s[i]=='0')continue;
			sum++;
		}
		if(sum>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		ap[id]=i;vis[i]=true;
		dfs(id+1/*,((s[id]=='0'||id-1-sum>=a[id])?sum:sum+1)*/);
		ap[id]=0;vis[i]=false;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdin);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	s=' '+s;
	dfs(1/*,0*/);
	cout<<ans;
	return 0;
} 
