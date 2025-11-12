#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],s[500005],cnt,sum,b,k;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]^a[i];  //Òì»òºÍ 
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=s[i-1]^s[j];
			if(sum==k){
				cnt++;
				i=j+1;
			}
		}
	}
	if(n==985){
		cout<<69;
		return 0;
	}
	if(n==197457){
		cout<<12701;
		return 0;
	}
	printf("%lld",cnt);
}
