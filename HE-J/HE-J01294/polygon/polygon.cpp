#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cout<<((n*(n-1)*(n-2))/6)%998244353;
	return 0;
}
