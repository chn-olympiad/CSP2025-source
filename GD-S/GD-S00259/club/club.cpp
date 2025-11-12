#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=210;
int T,n,dp[M+10][M+10][M+10],f[N+10],ans;
bool bo;
struct st{
	int a[3];
}t[N+10];
bool cmp(st x,st y){
	return x.a[0]>y.a[0];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		bo=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>t[i].a[0]>>t[i].a[1]>>t[i].a[2];
			if(t[i].a[1]!=0||t[i].a[2]!=0){
				bo=1;
			}
		}
		sort(t+1,t+1+n,cmp);
		ans=0;
		if(n<=200){
			memset(dp,0,sizeof dp);
			for(int i=1;i<=n;i++){
				for(int j=0;j<=i;j++){
					for(int k=0;k<=i-j;k++){
						if((i-j-k)>n/2||j>n/2||k>n/2){
							continue;
						}
						if(j+k<i){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+t[i].a[2]);
						}
						if(j>0){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+t[i].a[0]);
						}
						if(k>0){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+t[i].a[1]);
						}
						if(i==n){
							ans=max(ans,dp[i][j][k]);
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
		else{
			if(!bo){
				for(int i=1;i<=n/2;i++){
					ans+=t[i].a[0];
				}
				cout<<ans<<"\n";
			}
			else{
				int i=1,j=1;
				for(;i<=n/2;i++){
					ans+=t[i].a[0];
				}
				for(;j<i&&i<=n;j++){
					if(t[j].a[1]-t[j].a[0]+t[i].a[0]-t[i].a[1]>0){
						ans+=(t[j].a[1]-t[j].a[0]+t[i].a[0]);
						i++;
					}
				}
				for(;j<=n;j++){
					ans+=t[j].a[1];
				}
				cout<<ans<<"\n";
			}
		}
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

18
4
13

1
6
5 3 0
4 2 0
6 5 0
4 4 0
3 1 0
3 6 0

27
*/
