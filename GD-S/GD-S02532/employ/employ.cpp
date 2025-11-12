#include<bits/stdc++.h>
using namespace std;
long long a[507],b[507],x = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	int n,m;
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}for(int i = 1;i<=n;i++){
		x*=i;
	}x%=998244353;
	cout << x;
	return 0;
} 
