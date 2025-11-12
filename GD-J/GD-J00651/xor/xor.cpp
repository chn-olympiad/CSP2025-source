#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n,k; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	ll a[n+1]={0};
	bool b[n+1]={0};
	for(ll i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]=a[i]^a[i-1];
	}
	for(ll i = n;i>=1;i--){
		if(b[i]==1) continue;
		for(ll j = i;j>=1;j--){
			if(a[i]+a[j-1]==k){
				if(b[i]==1) break;
				m++;
				for(ll q=j;q<=i;q++) b[q]=1;
			}
		}
	}
	printf("%lld",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
