#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define PLL pair<long long,long long>
#define PB push_back
const int N=514514;
ll m,n,k,la;
ll a[N],d[N],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),d[i]=d[i-1]^a[i];
	ll l=0,r=1;
	if(a[1]==k){
	f[1]=1;
	la=1;	
	}
	for(int i=2;i<=n;i++){
		f[i]=f[la];
		for(int j=la+1;j<=i;j++)
			if((d[i]^d[j-1])==k){
				f[i]++;
	//			cout<<j<<" "<<i<<endl; 
				la=i;
				break;
			}
	}
	printf("%lld\n",f[n]);
	return 0;
	}
/**/

