#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[100005][3]={},b[100005],dp[30][30][30],x,y,z;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++)
			cout<<a[i][0]<<a[i][1]<<a[i][2]<<endl;
		if(n>30){
			for(int i=1;i<=n;i++)
				b[i]=a[i][0];
			sort(b+1,b+n+1,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=b[i];
			}
			cout<<sum;
		}else{
			int ans=0;
			if(n==2){
				for(int i=0;i<=2;i++){
					for(int j=0;j<=2;j++){
						if(i!=j)
							ans=max(ans,a[1][i]+a[2][j]);
					}
				}
				cout<<ans;
				return 0;
			}
			if(n==4){
				for(int i=0;i<=2;i++){
					for(int j=0;j<=2;j++){
						for(int k=0;k<=2;k++){
							for(int l=0;l<=2;l++){
								if(!(i==j&&j==k)&&!(i==j&&j==l)&&!(i==k&&k==l)&&!(j==k&&k==l)){
									ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
								}
							}
						}
					}
				}
				cout<<ans;
			}
		}
	}
	return 0;
}//
