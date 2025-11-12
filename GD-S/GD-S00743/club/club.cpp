#include<bits/stdc++.h>
using namespace std; 
const long long N=1e5+9;
long long n,a[N][4],c[4],b[4][N],ans,t;
long long main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		long long ma1,ma2,mj;
		for(long long i=1;i<=n;i++){
			ma1=-1,ma2=-1,mj=0;
			for(long long j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(a[i][j]>ma1){
					ma1=a[i][j];
					mj=j;
				}
			}
			for(long long j=1;j<=3;j++){
				if(a[i][j]>ma2&&mj!=j){
					ma2=a[i][j];
				}
			}
			ans+=ma1;
			c[mj]++;
			b[mj][c[mj]]=ma1-ma2;
		}
		for(long long i=1;i<=3;i++){
			sort(b[i]+1,b[i]+c[i]+1);
			if(c[i]>n/2){
				for(long long j=1;j<=c[i]-n/2;j++){
					ans-=b[i][j];
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
}
