#include<bits/stdc++.h>//诡异代码时间复杂度O(3^n),这太难了:(
#define endl '\n'
using namespace std;
long long t,n,ans=0;
long long a[100005][4];
long long vis[4];
void dfs(long long x,long long sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]<n/2){
			vis[i]++;
			dfs(x+1,sum+a[x][i]);
			vis[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
//3 
//4 
//4 2 1 
//3 2 4 
//5 3 4 
//3 5 1 
//4 
//0 1 0 
//0 1 0 
//0 2 0 
//0 2 0 
//2 
//10 9 8 
//4 0 0

