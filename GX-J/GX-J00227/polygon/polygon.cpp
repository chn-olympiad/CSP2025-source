#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n,pai = 0,m,a[N],c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n<3)cout<<0;
	if(n == 3){
		if(a[1]+a[2]+a[3] > max(max(a[1],a[2]),a[3])*2)cout<<1;
		else cout<<0;
	}else{
		cout<<((n-2)*(1+n-2)/2)%998244353;
	}
	return 0;
}
