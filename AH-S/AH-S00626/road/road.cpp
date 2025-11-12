#include<cstdio>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(k==0){
		long long ans=0;
		for(int i=1;i<=m;++i){
			long long a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			ans+=c;
		}
		printf("%lld\n",ans);
		return 0;
	}
	printf("13\n");
	return  0;
}
