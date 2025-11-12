#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n;
bool ass(long long i){
	int b=0;long long a=i;
	while(a!=0){a=a&(a-1);b++;}
	if(b>=3)return 1;
	else return 0;
}
void mainn(int a[]){
	
	for(long long i=7;i<(1<<n);i++){
		if(ass(i)){
			long long tmp=i,sum=0,Max=0;
			for(int i=0;tmp!=0;i++){
				if(tmp&1){sum+=a[i];Max=max(Max,(long long)a[i]);}
				tmp>>=1;
			}
			if(sum>Max*2)ans++;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	mainn(a);
	printf("%lld",ans%998244353);

	return 0;
}
