#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long int n,m,a=1,b=1;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		a*=i;
	}
	for(int i = 1;i<=n-m;i++){
		b*=i;
	}
	cout<<a/b%998244353;
}
