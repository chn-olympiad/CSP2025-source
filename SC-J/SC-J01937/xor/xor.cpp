#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
const int maxn=1e6+5;
int a[maxn];
int sum;
int f[maxn];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
    if(k==0){
		for(int i=1;i<=n;++i){
			if(a[i]==a[i+1]&&a[i]==1){
				sum++;
			++i;
			}else if(a[i]==0){
				++sum;
			}
		}
	}else if(k==1){
		for(int i=1;i<=n;++i){
			if(a[i]==1){
				++sum;
//				++i;
			}else if(a[i]!=a[i+1]){
				sum++;
				++i;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}