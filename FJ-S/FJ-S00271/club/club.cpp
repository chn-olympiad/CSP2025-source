#include<bits/stdc++.h>
using namespace std;
int t,n,a[210][4],dp[2][105][105][105];
struct node{
	int a;
	bool b;
}num[100010];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		if(n>=200){
			int a[100010],b[100010],ans=0,sumx=0,sumy=0;
			for(int i=1;i<=n;i++){
				int a,b,c;
				cin >> a >> b >> c;
				if(a<b){
					ans+=a;
					num[i].a=b-a;
					num[i].b=0;
				}
				else{
					ans+=b;
					num[i].a=a-b;
					num[i].b=1;
				}
			}
			sort(num+1,num+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(!num[i].b){
					if(sumx<n/2) ans+=num[i].a,sumx++;
					else sumy++;
				}
				else{
					if(sumy<n/2) ans+=num[i].a,sumy++;
					else sumx++;
				}
			}
			cout << ans << '\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin >> a[i][j];
		}
		for(int i=0;i<2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					for(int l=0;l<=n/2;l++){
						dp[i][j][k][l]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			int x=i%2,y=!x;
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					for(int l=0;l<=n/2;l++){
						dp[x][j][k][l]=0;
					}
				}
			}
			for(int j=min(n/2,i);j>=0;j--){
				for(int k=min(n/2,i-j);k>=0;k--){
					for(int l=min(n/2,i-j-k);l>=0;l--){
						if(j) dp[x][j][k][l]=max(dp[x][j][k][l],dp[y][j-1][k][l]+a[i][1]);
						if(k) dp[x][j][k][l]=max(dp[x][j][k][l],dp[y][j][k-1][l]+a[i][2]);
						if(l) dp[x][j][k][l]=max(dp[x][j][k][l],dp[y][j][k][l-1]+a[i][3]);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					ans=max(ans,dp[0][i][j][k]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
