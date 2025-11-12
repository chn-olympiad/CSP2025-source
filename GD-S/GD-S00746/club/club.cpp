#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,t;
int arr[maxn][4];
bool vis[maxn][4];
int f[4];
long long ans;
long long dfs(int i,int c,long long num){
	if(i>n||f[c]>n/2)return 0;
	ans=max(ans,num);
	for(int j=1;j<=3;j++){
		if(vis[i+1][j]==1)continue;
		f[j]++;
		vis[i+1][j]=1;
		dfs(i+1,j,(num+arr[i+1][j]));
		vis[i+1][j]=0;
		f[j]--;
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
		}
		dfs(0,0,0);
		cout<<ans<<"\n";
		ans=0;
		memset(arr,0,sizeof(arr));
	}
	return 0;
} 
