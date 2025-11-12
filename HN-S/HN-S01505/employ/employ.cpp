#include<iostream>
using std::cout;
using std::cin;
int n,m;
long long jc(int x) {
	if(x<=2)
		return x;
	return x*jc(x-1);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cout<<jc(n);
	return 0;
}
