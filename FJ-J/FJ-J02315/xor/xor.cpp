#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s,a[1000000],sum,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&s);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		if(a[i]==s){
			sum++;
			t=0;
			continue;
		}
		else if(t==0){
			t=a[i];
		}
		else{
			t^=a[i];
			if(t==s){
				t=0;
				sum++;
			}
		} 
	}
	printf("%lld",sum);
	return 0;
}
