#include<iostream>

#define lld long long int
#define MAXN
using namespace std;
long long mod=998244353;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<1%mod;
	}
	return 0;
}

