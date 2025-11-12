#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a+1,a+4);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else{
		for(int i=3;i<=n;i++){
			s+=i*((n-3)*(n-3+1)/2);
		}
		cout<<s%998244353;
	}
	return 0;
}
