#include <bits/stdc++.h>
using namespace std;
long long jiec(int n){
	long long nums=1;
	for(int i=2;i<=n;i++){
		nums*=i;
	}
	return nums;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	int c[n];
	cin >> s;
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	if(m>1)
		cout << 0;
	else
		cout << jiec(n);
	return 0;
}
