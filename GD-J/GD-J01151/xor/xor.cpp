#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,k,a,Xor[N],cur,start,ans=1;
struct cein{
	int st;
	int ed;
}sum[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		Xor[i]=Xor[i-1]^a;
	}
	for(int i=n;i>=1;i--)
		for(int j=i;j>=1;j--)
			if((Xor[i]^Xor[j-1])==k){
				sum[++cur].st=j;
				sum[cur].ed=i;
				break;
			}
	start=sum[1].st;
	for(int i=2;i<=cur;i++){
		if(sum[i].ed<start) ans++,start=sum[i].st;
		else start=max(start,sum[i].st);
	}
	printf("%lld",ans);
	return 0;
}

