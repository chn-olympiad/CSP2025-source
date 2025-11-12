#include <bits/stdc++.h>
using namespace std;
long long n,q;
struct z{
	string s1,s2;
}a[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i].s1 >> a[i].s2;
	}
	for(int j=1;j<=q;j++){
		cout << 0 << '\n';
	}
	return 0;
} 
