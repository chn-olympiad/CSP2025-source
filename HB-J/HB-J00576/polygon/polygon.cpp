#include<bits/stdc++.h>
using namespace std;

int a[5005];
int n;
bool flag_B = true;
unsigned long long ans;
unsigned long long mod = 998244353;
unsigned long long allsum;
unsigned long long calc[5005];

long long C(long long m,long long n){
	long long mot=1,chi=1;
	if(n==m){
		return 1;
	}
	if(n>m/2){
		return C(m,m-n);
	}else{
		for(int i=1;i<=n;i++){
			mot*=i;
		}
		for(int i=1;i<=n;i++){
			chi*=(m-i+1);
		}
		return chi/mot;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] != 1){
			flag_B = false;
		}
	}
	if(n == 3){
		int maxl = max(max(a[1],a[2]),a[3]);
		if((a[1]+a[2]+a[3]) > maxl*2){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		for(int i=3;i<=n;i++){
			allsum = (allsum+C(n,i))%mod;
		}
		if(flag_B){
			cout << allsum;
		}else{
			cout << allsum/2;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
