#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[10000+10][3+1],m[10010],dp[10010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	LL t;cin>>t;
	while(t--){
		LL n,testn=0;
		cin>>n;
		for(LL i=1;i<=n;i++){
			for(LL j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(LL i=1;i<=n;i++){
			m[i]=a[i][1]-a[i][2];
		}
		for(LL i=1;i<=n;i++){
			if(a[i][2]!=0)break;
			if(i==n&&a[i][2]==0)testn++;
		}
		for(LL i=1;i<=n;i++){
			if(a[i][3]!=0)break;
			if(i==n&&a[i][3]==0)testn++;
		}
		if(n==2){
			LL max1=0;
			for(LL j=1;j<=3;j++){
				for(LL i=1;i<=3;i++){
					if(i==j){
						continue;
					}
					max1=max(a[1][j]+a[2][i],max1);
				}
			}
			cout<<max1<<endl;
		}
		if(testn==2){
			LL max1=0,maxn=0;
			for(LL i=1;i<=n/2;i++){
				for(LL j=1;j<=n;j++){
					max1=max(a[j][1],max1);
				}
				maxn+=max1;
			}
			cout<<maxn<<endl;
		}
		if(testn==2){
			LL ans=0;
			for(int i=1;i<=n;i+=2){
				if(m[i]>=0){
					ans+=a[i][1];
				}
				
			}
			for(int i=2;i<=n;i+=2){
				if(m[i]>=0){
					ans+=a[i][2];
				}
				
			}
		}
		
		
	}
	return 0;
}
