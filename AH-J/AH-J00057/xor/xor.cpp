#include<bits/stdc++.h>
using namespace std;
int n,k,a,b[500005],r;
long long m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		b[i]=a^b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=r;j<i;j++){
			int x=b[i]^b[j];
			if(x==k){
				m++,r=i;
				break;
			}
		}
	}
	printf("%lld",m);
	return 0;
}
