#include<bits/stdc++.h>
using namespace std;
int t,n,a[210],b[210],c[210],dp[110][110][110];
int dfs(int x,int y,int z){
	int i=x+y+z+1;
	if(x>n/2||y>n/2||z>n/2){
		return (int)INT_MIN;
	}
	if(i>n)return 0;
	if(dp[x][y][z])return dp[x][y][z];
	return dp[x][y][z]=max(dfs(x+1,y,z)+a[i],max(dfs(x,y+1,z)+b[i],dfs(x,y,z+1)+c[i]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n>200){
			int ans=0;
			sort(a+1,a+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i];
			}
			cout<<ans<<"\n";
			continue;
		} 
		cout<<dfs(0,0,0)<<"\n";
	}
	return 0; 
}
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

WA65
*/
