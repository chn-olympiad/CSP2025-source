#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int n,k;
int num[MAXN];
int sum0=0,sum1=0;
signed main(){
	//1xor1==0!!!
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
		if(num[i]==0)
			sum0++;
		else
			sum1++;
	}
	cout<<sum1/2;
	return 0;
}
