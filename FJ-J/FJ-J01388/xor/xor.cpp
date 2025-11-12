#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],n,k,s=0,ans=0;
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	a[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			s+=1;
		}
	} 
	for(int i=2;i<=n;i++){
		ans=0;
		for(int j=i-1;j<=n;j++){
			ans+=a[j]|a[j-1];
			if(ans==k){
				s+=1;
			}
		}
	}
	printf("%lld",s);
	return 0;
} 
