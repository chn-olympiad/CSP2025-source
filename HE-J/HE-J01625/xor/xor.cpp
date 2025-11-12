#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],b[500005];
bool x=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(ll i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			x=0;
		}
	}
	if(x==1){
		if(k==0){
			cout<<n/2;
		}
		if(k==1){
			cout<<n;
		}
	}
	else{
		for(ll i=1;i<=n;++i){
			b[i]=b[i-1]^a[i];
		}
		for(ll i=1;i<=n;++i){
			cout<<b[i];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
