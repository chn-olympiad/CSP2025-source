#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N=1e5+10; 
int T,n,n1;
int a[N][4],dp[N][500][4];//ii,,cl
int v[N][4],ans=0;
int a10[N],a20[N];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int ii,int a1,int a2,int a3,int u1,int u2,int u3){
//	cout<<ii<<' '<<a1<<' '<<a2<<' '<<a3<<' '<<u1<<' '<<u2<<' '<<u3<<endl;
	if(ii>n){
		ans=max(a1+a2+a3,ans);
		return;
	}
	for(int i=ii;i<=n;i++){
		if(u1<n1)dfs(ii+1,a1+a[ii][1],a2,a3,u1+1,u2,u3);
		if(u2<n1)dfs(ii+1,a1,a2+a[ii][2],a3,u1,u2+1,u3);
		if(u3<n1)dfs(ii+1,a1,a2,a3+a[ii][3],u1,u2,u3+1);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n;
		n1=n/2;
		int a02=0,a03=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]==0)a02++;
			if(a[i][3]==0)a03++;
		}
		if(a03==n){
			if(a02==n){
				for(int i=1;i<=n;i++)
					a10[i]=a[i][1];
				sort(a10+1,a10+1+n,cmp);
				for(int i=1;i<=n1;i++){
					ans+=a10[i];
				}
				cout<<ans;
				return 0;
			}
//			for(int i=1)
		}
		dfs(1,0,0,0,0,0,0);
		cout<<ans<<endl;
		/*
		for(int j=n1;j>=0;j--){
			for(int i=1;i<=n;i++){
				for(int k=0;k<3;k++){
					dp[i][j][k]=max(dp[i-1][n1-j][k],max(dp[i-1][j][(k+1)%3],dp[i-1][j][(k+2)%3]))+a[i][k+1];
				}
				dp[i][j][3]=max(dp[i][j][0],max(dp[i][j][1],dp[i][j][2]));
			}
		}
		cout<<dp[n][n1][3]<<endl;
//		*/
	}
	return 0;
}
/*
3
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
dp[i-j][k]+a[i][k]
dp[i]=max(dp[i],dp[j-v[i]]+w[i])
*/
