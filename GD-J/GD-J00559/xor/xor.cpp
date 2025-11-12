#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e5+5;
int a[maxn],n,k,z,mx,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){
			z++;
		}
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	if(k==0 && z==n){
		printf("%d",n>>1);
		return 0;
	}
	if(k<=1 && mx<=1){
		printf("%d",k==1?sum:n-sum);
		return 0;
	}
	return 0;
}
