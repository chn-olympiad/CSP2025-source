#include <bits/stdc++.h>
using namespace std;
long long a[100005][4];
long long c[100005];
long long js[3];
long long s[100005];
long long len=0;
int main(){
//	freopen("club5.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	scanf ("%lld",&t);
	while (t--){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(s,0,sizeof(s));
		js[0]=js[1]=js[2]=len=0;
		long long n;
		scanf ("%lld",&n);
		for (long long i=1;i<=n;++i)
			for (long long j=0;j<3;++j)
				scanf ("%lld",&a[i][j]);
		long long ans=0;
		for (long long i=1;i<=n;++i){
			if (a[i][0]>=a[i][1] && a[i][0]>=a[i][2]){
				js[0]++;
				a[i][3]=0;
			}else
				if (a[i][1]>=a[i][0] && a[i][1]>=a[i][2]){
					js[1]++;
					a[i][3]=1;
				}else
					if (a[i][2]>=a[i][0] && a[i][2]>=a[i][1]){
						js[2]++;
						a[i][3]=2;
					}
			sort(&a[i][0],&a[i][3]);
			c[i]=a[i][2]-a[i][1];
			ans+=a[i][2];
		}
		/*
		for (long long i=1;i<=n;++i){
			for (long long j=0;j<=3;++j){
				printf ("%lld ",a[i][j]);
			}
			printf ("%lld",c[i]);
			puts("");
		}
		printf ("%lld\n",ans);
		for (long long j=0;j<3;++j)
			printf ("%lld ",js[j]);
		puts("");
		*/
		if (js[0]>n/2){
			for (long long i=1;i<=n;++i)
				if(a[i][3]==0)
					s[++len]=c[i];
			sort(s+1,s+len+1);
			long long o=1;
			while(js[0]>n/2){
				ans-=s[o];
				o++;
				js[0]--;
			}
//			puts("0__________");
		}else{
			if (js[1]>n/2){
				for (long long i=1;i<=n;++i)
					if(a[i][3]==1)
						s[++len]=c[i];				
				sort(s+1,s+len+1);
				long long o=1;
				while(js[1]>n/2){
					ans-=s[o];
					o++;
					js[1]--;
				}		
//				puts("1__________");
			}else{
				if (js[2]>n/2){
					for (long long i=1;i<=n;++i)
						if(a[i][3]==2)
							s[++len]=c[i];
					sort(s+1,s+len+1);
					long long o=1;
					while(js[2]>n/2){
						ans-=s[o];
						o++;
						js[2]--;
					}
//					puts("2__________");
				}
			}
		}
		printf ("%lld\n",ans);
	}
	return 0;
}
