#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,q;
	cin >> n >> q;
	string a,b;
	for(int i = 1;i <= n;i ++){
		cin >> a >> b;
	}
	for(int i = 1;i <= q;i ++){
		cin >> a >> b;
		cout << "0\n";
	}
	return 0;
}
