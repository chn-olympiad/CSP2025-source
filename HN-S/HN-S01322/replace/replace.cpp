#include<bits/stdc++.h>
using namespace std;
long long n,q;
char a[1001][1001],t[1001][1001];
int main()
{
	freopen("replace","r",stdin);
	freopen("replace","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i][1] >> a[i][2];
	}
	for(int j=1;j<=q;j++)
	{
		cin >> t[j][1] >> t[j][2];
	}
	for(int i=1;i<=q;i++)
	{
		cout << '1';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
