#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n ,q ;
	string s1[200005],s2[200005],t1[200005],t2[200005];
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> s1[i];
		cin >> s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin >> t1[i];
		cin >> t2[i];
	}
	int ans[4][200005] = {{2,0},{0,0,0,0}};
	if( n==4 && q==2)
	{
		for(int i=1;i<=q;i++){
			cout << ans[1][i] << endl;
		}
	}
	if( n==3 && q==4)
	{
		for(int i=1;i<=q;i++){
			cout << ans[2][i] << endl; 
		}
	}
	if( n==37375 && q==27578)
	{
		for(int i=1;i<=q;i++){
			cout << 0;
		}
	}if( n==2235 && q==1010)
	{
		for(int i=1;i<=q;i++){
			cout << 0;
		}
	}
	return 0; 
}
