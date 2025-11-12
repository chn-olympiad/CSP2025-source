#include<iostream>
using namespace std;

typedef long long lld;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	lld s = 1;
	cin>>n;
	for(lld i = 1; i <= n; i++){
		s *= i;
	}
	cout<<s;
	return 0;
}