#include<bits/stdc++.h>
using namespace std;

const int N=505,mod=998244353;
int n,m;
bool s[N];
int c[N];
bool vis[N];
int cnt;

void dfs(int k,int r)
{
	if(k>n){
		if(n-r>=m){
			cnt++;
		}	
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(r<c[i]&&s[k]==1) dfs(k+1,r);
			else dfs(k+1,r+1);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1,0);
	cout<<cnt;
	return 0;
}
