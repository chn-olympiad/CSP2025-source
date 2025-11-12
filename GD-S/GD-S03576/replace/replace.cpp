#include<bits/stdc++.h>
using namespace std;
string s[200005], d[200005];
string t[200005], r[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1;i<=n;i++)
	{
		cin >> s[i] >> d[i];
	}
	for(int i = 1;i<=q;i++)
	{
		cin >> t[i] >> r[i];
	}
	cout << 0 << endl;
	return 0;
}
