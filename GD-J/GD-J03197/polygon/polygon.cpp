#include<cstdio>
#include<algorithm>
#define mod 998244353
#define ll long long
//#define int long long
using namespace std;
int list[5500]={};

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",list+i);
	}
	std::sort(list,list+n,[](const short& x,const short& y){return x > y;});;
	if(list[0]==1){
		printf("%lld",(1+n)*(long long)n/2%mod);
		return 0;
	}else{
		long long l=0;
		long long ret=0;
		for(;l<(1<<(long long)n);l++){
//			printf("%d\n",l);
			int sum=0;
			for(int cl=l,j=n-1;cl;cl/=2,j--){
				if(cl%2)sum+=list[j];
				if(cl==1&&sum>list[j]*2){
//					printf("	%d\n",j);
					ret++;
					ret%=mod;
				}
			}
		}
		printf("%d",ret);
	}
	
} 
