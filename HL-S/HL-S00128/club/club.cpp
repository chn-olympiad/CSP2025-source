#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int t;
int a[N][5];
int v[5];
long long ans[10];
long long sum;
bool vis[N][5];
void dfs(int y,int x,int n){
//	cout <<sum<<" ";
	ans[y] = max(ans[y],sum);
	if(x==n+1){
		return ;
	}
	for(int i = 1;i <= 3;i++){
		if(n/2==v[i]||vis[x][i]==1){
			continue;
		}
		v[i]++;
		sum+=a[x][i];
		vis[x][i]=1;
		dfs(y,x+1,n);
		v[i]--;
		sum-=a[x][i];
		vis[x][i]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	for(int i = 1;i <= t;i++){
		memset(a,0,sizeof(a));
		int n;
		cin >>n;
		for(int j = 1;j <= n;j++){
			cin >>a[j][1]>>a[j][2]>>a[j][3];
		}
		dfs(i,1,n);
	}
	for(int i = 1;i <= t;i++){
		cout <<ans[i]<<endl;
	}
	return 0;
}