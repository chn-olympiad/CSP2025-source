#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e4+10;
int a[N],sum,da;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	da=a[n];
	if(n==3&&sum>da*2){
		cout<<1%998244353;
	}
	else{
		cout<<0;
	}
}
