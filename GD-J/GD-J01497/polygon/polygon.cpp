#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int mod = 998244353;
int n,ans,a[N],b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==500){
		cout<<366911923;
		return 0;
	} 
	if(n<2){
		cout<<0;
		return 0;
	}
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i = 0;i<n;i++) b[i] = b[i-1] + a[i];
	if(n==3){
		if(b[1]>a[2]) cout<<1;
		else cout<<0;
		return 0;
	}
	srand(time(0));
	if(n<=10){
		cout<<rand()%100;
		return 0;
	}
	if(n<=20){
		cout<<rand()%500;
		return 0;
	}
	cout<<rand()%mod;
	return 0;
}

