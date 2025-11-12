#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	std::cin>>n;
	long long a[n+5],qiu=0;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
		qiu+=a[i];
	}
	std::cout<<qiu%998244353;
	
	return 0;
}
