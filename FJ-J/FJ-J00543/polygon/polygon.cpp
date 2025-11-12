#include<bits/stdc++.h>
using namespace std;long long a[5010];long long n;
int ab(long long x){long long b=0,c=0,d=0;
	for(long long i=0;i<=n-1;i++){
		if(1<<i&x){
			b++;
			c=max(a[i+1],c);
			d+=a[i+1];
		}
	}
	if(b>=3&&d>c*2)return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}long long ans=0;
	for(long long i=1;i<=1<<n;i++){
		ans+=ab(i);ans%=998244353;
	}cout<<ans;
	return 0;
}
