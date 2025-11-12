#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	s=n/3;
	cout<<s%998244353;
	return 0;
}	
