#include<bits/stdc++.h>
using namespace std;
int a[6000];
long long w = 998244353;
long long p(int k){
	int ans = 1;
	while(k--){
		ans = ((ans % w) * 2) % w;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	long long n ;
	cin>>n;
	
	for(int i = 1 ;i <= n;i++){
		cin>>a[i];
	}
	long long an = 1 + n + (n*(n-1))/2;
	long long ans = p(n);
	if(ans >= an){
		cout<<ans - an;
		return 0;
	}else{
		long long d = w - an;
		d +=ans;
		cout<<d;
		return 0;
	}
 
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
