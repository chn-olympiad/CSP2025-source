#include<cstdio>
#include<algorithm>
using namespace std;
const long long maxn=1e5+5;
const long long inf=1e18;
long long n,T,a,b,c;
long long ans,f[maxn][5],d[5],cl[maxn],l,k[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ans=0;
		scanf("%lld",&n);
		l=n/2;
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&f[i][1],&f[i][2],&f[i][3]);
			if(f[i][1]>=f[i][2]&&f[i][1]>=f[i][3]){
				d[1]++;
				cl[i]=1;
				ans+=f[i][1];
			}
			else if(f[i][2]>=f[i][1]&&f[i][2]>=f[i][3]){
				d[2]++;
				cl[i]=2;
				ans+=f[i][2];
			}
			else{
				d[3]++;
				cl[i]=3;
				ans+=f[i][3];
			}
		}
		long long r=0;
		if(d[1]>l)r=1;
		else if(d[2]>l)r=2;
		else if(d[3]>l)r=3;
		if(r){
			long long cnt=0;
			for(long long i=1;i<=n;i++){
				if(cl[i]==r){
					++cnt;
					k[cnt]=inf;
					for(long long j=1;j<=3;j++){
						if(j==r)continue;
						if(f[i][r]-f[i][j]<k[cnt]){
							k[cnt]=f[i][r]-f[i][j];
						}
					}
				}
			}
			sort(k+1,k+1+cnt);
			for(long long i=1;i<=d[r]-l;i++)ans-=k[i];
		}
		printf("%lld\n",ans);
		d[1]=d[2]=d[3]=0;
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
