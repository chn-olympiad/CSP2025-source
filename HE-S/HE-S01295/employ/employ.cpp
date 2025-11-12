#include <bits/stdc++.h>
using namespace std;

const int N = 998244353;
int a[507];

const long long jc(int n){
	if(n==1)
		return 1;
	return n*jc(n-1);
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	string s;
	
	cin >> n >> m;
	cin >> s;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	cout << jc(n)%N;
	return 0;
}
