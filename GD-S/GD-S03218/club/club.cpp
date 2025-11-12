#include<bits/stdc++.h>
using namespace std;
long long t;
struct d{
	long long s1,s2,s3,x;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,a[10005][4];
		d f[10005][4];
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		f[0][1].x=0;f[0][2].x=0;f[0][3].x=0;
		f[0][1].s1=0;f[0][2].s1=0;f[0][3].s1=0;
		f[0][1].s2=0;f[0][2].s2=0;f[0][3].s2=0;
		f[0][1].s3=0;f[0][2].s3=0;f[0][3].s3=0;
		for(int i=1;i<=n;i++){
			long long ma1=0,ma2=0,ma3=0,ff1=0,ff2=0,ff3=0;
			if(i==1){
				f[i][1].x=a[i][1];f[i][2].x=a[i][2];f[i][3].x=a[i][3];
				continue;
			}
			//1
			if(f[i-1][1].s1<n/2){
				if(ma1<f[i-1][1].x+a[i][1]){
					ma1=f[i-1][1].x+a[i][1];
					ff1=1;
				}
			}if(f[i-1][1].s2<n/2){
				if(ma1<f[i-1][1].x+a[i][2]){
					ma1=f[i-1][1].x+a[i][2];
					ff1=2;
				}
			}if(f[i-1][1].s3<n/2){
				if(ma1<f[i-1][1].x+a[i][3]){
					ma1=f[i-1][1].x+a[i][3];
					ff1=3;
				}
			}if(ff1==1){
				f[i][1].s1=f[i-1][1].s1+1;
			}if(ff1==2){
				f[i][1].s2=f[i-1][1].s2+1;
			}if(ff1==3){
				f[i][1].s3=f[i-1][1].s3+1;
			}
			f[i][1].x=ma1;
			//2
			if(f[i-1][2].s1<n/2){
				if(ma2<f[i-1][2].x+a[i][1]){
					ma2=f[i-1][2].x+a[i][1];
					ff2=1;
				}
			}if(f[i-1][2].s2<n/2){
				if(ma2<f[i-1][2].x+a[i][2]){
					ma2=f[i-1][2].x+a[i][2];
					ff2=2;
				}
			}if(f[i-1][2].s3<n/2){
				if(ma2<f[i-1][2].x+a[i][3]){
					ma2=f[i-1][2].x+a[i][3];
					ff2=3;
				}
			}if(ff2==1){
				f[i][2].s1=f[i-1][2].s1+1;
			}if(ff2==2){
				f[i][2].s2=f[i-1][2].s2+1;
			}if(ff2==3){
				f[i][2].s3=f[i-1][2].s3+1;
			}
			f[i][2].x=ma2;
			//3
			if(f[i-1][3].s1<n/2){
				if(ma3<f[i-1][3].x+a[i][1]){
					ma3=f[i-1][3].x+a[i][1];
					ff3=1;
				}
			}if(f[i-1][3].s2<n/2){
				if(ma3<f[i-1][3].x+a[i][2]){
					ma3=f[i-1][3].x+a[i][2];
					ff3=2;
				}
			}if(f[i-1][3].s3<n/2){
				if(ma3<f[i-1][3].x+a[i][3]){
					ma3=f[i-1][3].x+a[i][3];
					ff3=3;
				}
			}if(ff3==1){
				f[i][3].s1=f[i-1][3].s1+1;
			}if(ff3==2){
				f[i][3].s2=f[i-1][3].s2+1;
			}if(ff3==3){
				f[i][3].s3=f[i-1][3].s3+1;
			}
			f[i][3].x=ma3;
		}
		printf("%lld\n",max(f[n][1].x,max(f[n][2].x,f[n][3].x)));
	}
	
	return 0;
} 
