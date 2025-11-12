#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000006][3];
int T,n,maxn=-1;
int c[2][10005][10005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		maxn=-1;
		cin>>n;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
			memset(c,0,sizeof c);
			c[1][1][0]=a[1][0];
			c[1][0][1]=a[1][1];
			c[1][0][0]=a[1][2];
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						c[(i+1)%2][j+1][k]=max(c[i%2][j][k]+a[i+1][0],c[(i+1)%2][j+1][k]);
						c[(i+1)%2][j][k+1]=max(c[i%2][j][k]+a[i+1][1],c[(i+1)%2][j][k+1]);
						c[(i+1)%2][j][k]=max(c[i%2][j][k]+a[i+1][2],c[(i+1)%2][j][k]);
					}
				}
			}
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(n-j-k-1<=n/2)maxn=max(c[0][j][k],maxn);
				}
			}
		cout<<maxn<<endl;
	}
	return 0;
} 
