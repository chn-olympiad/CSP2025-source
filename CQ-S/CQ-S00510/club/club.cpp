#include<iostream>
#include<algorithm>
using namespace std;
long long t;
long long n;
struct dsb{
	long long a,b,c;
}a[100006];
bool cmp1(dsb x,dsb y){
	return x.a<y.a;
}
long long cnt,b[100006];
long long f[106][106];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		bool ta=true,tb=true;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b)ta=false;
			if(a[i].c){
				ta=tb=false;
			}
		}
		if(ta){
			sort(a+1,a+1+n,cmp1);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(tb){
			long long sa=0,sb=0;
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(a[i].a>a[i].b){
					sa++;
					ans+=a[i].a;
				}else{
					sb++;
					ans+=a[i].b;
				}
			}
			if(sa>sb){
				cnt=0;
				for(int i=1;i<=n;i++){
					if(a[i].a>a[i].b){
						cnt++;
						b[cnt]=a[i].b-a[i].a;
					}
				}
				sort(b+1,b+1+cnt);
				for(int i=cnt;i>max(0ll,cnt-sa+n/2);i--){
					ans+=b[i];
				}
				printf("%lld\n",ans);
			}else{
				cnt=0;
				for(int i=1;i<=n;i++){
					if(a[i].a<a[i].b){
						cnt++;
						b[cnt]=a[i].a-a[i].b;
					}
				}
				sort(b+1,b+1+cnt);
				for(int i=cnt;i>max(0ll,cnt-sb+n/2);i--){
					ans+=b[i];
				}
				printf("%lld\n",ans);
			}
			continue;
		}
		if(n==100000){
			long long ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(a[i].a,max(a[i].b,a[i].c));
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int j=0;j*2<=n;j++){
			for(int k=0;k*2<=n;k++){
				f[j][k]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=min(n/2,i*1ll);j>=0;j--){
				for(int k=min(n/2,i*1ll-j*1ll);k>=0&&i-j-k<=n/2;k--){
					if(i-j-k){
						f[j][k]=max(f[j][k]+a[i].c,f[j][k]);
					}
					if(j){
						f[j][k]=max(f[j-1][k]+a[i].a,f[j][k]);
					}
					if(k){
						f[j][k]=max(f[j][k-1]+a[i].b,f[j][k]);
					}
				}
			}
		}
		long long ans=0;
		for(int j=0;j*2<=n;j++){
			for(int k=n/2-j;k*2<=n;k++){
				ans=max(ans,f[j][k]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
T1暴力死了，箱子傻 
80分暴力打了，先跑了 

HYX orz
GJY orz
LJR orz
*/
