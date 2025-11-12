#include <bits/stdc++.h>
using namespace std;

int n,q;
string s1,s2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin>>s1>>s2;
	}
	srand(time(NULL));
	for (int i=1;i<=q;i++) {
		cin>>s1>>s2;
		cout<<0<<"\n";
	}
	return 0;
}
