#include<bits/stdc++.h>
using namespace std;
int n,a[10010],sum=1,s=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=3;i--){
		s=(s+n-1);
		sum+=s;
		sum%=(998244353);
	}
	cout<<sum;
	return 0;
}
