#include <bits/stdc++.h>
using namespace std;
//2048MB
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n>> q;
	for(int i = 1;i <= n;i++){
		string x,y;
		cin >> x>>y;
	}
	for(int i = 1;i <= q;i++){
		string x,y;
		cin >> x>>y;
		if(x == y)cout << 0<<'\n';
		else cout << 1<<'\n';
	}
    return 0;
}
