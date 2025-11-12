#include<bits/stdc++.h>
#define int long long
const int N=5e5+22;
using namespace std;
int n,k,a[N],pre[N],cnt,pos;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),pre[i]=pre[i-1]^a[i];
	pos=1;
	for(int i=1;i<=n;i++){
		for(int j=pos;j<=i;j++){
			if((pre[i]^pre[j-1])==k){
//				cout<<i<<' '<<j<<' '<<((pre[i]^pre[j-1])==k)<<endl;
				cnt++;
				pos=i+1;
				break;
			}
		}
	}
	printf("%lld",cnt);
}
