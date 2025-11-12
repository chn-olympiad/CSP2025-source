#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500005],ans,x[500005],k,now=1;
//l~r = x[r]^x[l-1];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
		x[i]=x[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=now;r<=l;r++){
			if((x[l]^x[r-1])==k){
				//cout<<l<<" "<<r<<endl;
				ans++;
				now=l+1;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
/*
4 0
2 1 0 3
*/
//12701
