#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
unsigned long long attb(int h,int l){
	unsigned long long ans = 1;
	for(int i = h;i>=l;--i){
		ans%=mod;
		ans*=i;
	}
	return ans%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);



	int n,m;
	cin>>n>>m;
	
	cout<<(attb(n,m+1)/attb(n-m,1));





	fclose(stdin);
	fclose(stdout);
	return 0;
}
