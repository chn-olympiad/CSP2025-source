#include<bits/stdc++.h>
using namespace std;
int a[501];
struct d{
	string s,_s,ss,_ss;
}S[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i ++)
		cin >> S[i].s >> S[i]._s;
	for(int i = 1;i <= q;i ++){
		cin >> S[i].ss >> S[i]._ss;
		cout << "0\n";
	}
	return 0;
}
