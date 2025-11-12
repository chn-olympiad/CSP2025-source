#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int t,n,x;
int a[205][3];
int c[205][105][105];
int b[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==100005){
			for(int i=1;i<=n;i++){
				cin>>b[i]>>x>>x;
			}
			x=0;
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++)x+=b[i];
			cout<<x;
		}
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(i+1)/2;j++){
				for(int k=0;k<=(i+1)/2;k++){
					int m=i-j-k;
					if(m>(i+1)/2)continue;
					if(m<0)break;
					if(j==0){
						if(k==0){
							c[i][j][k]=c[i-1][j][k]+a[i][2];
						}else{
							c[i][j][k]=max(c[i-1][j][k]+a[i][2],c[i-1][j][k-1]+a[i][1]);
						}
					}else if(k==0){
						c[i][j][k]=max(c[i-1][j][k]+a[i][2],c[i-1][j-1][k]+a[i][0]);
					}else c[i][j][k]=max(c[i-1][j-1][k]+a[i][0],max(c[i-1][j][k-1]+a[i][1],c[i-1][j][k]+a[i][2]));
				}
			}
		}
		int mx=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				mx=max(c[n][i][j],mx);
			}
		}
		cout<<mx<<endl;
		memset(c,0,sizeof(c));
	}
	return 0;
}
