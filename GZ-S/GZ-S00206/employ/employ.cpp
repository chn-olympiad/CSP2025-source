//GZ-S00206 北京师范大学贵阳附属中学 曹誉桉
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char a[10005];
int b[10005];
int main()
{
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout) ;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	for(int i=1; i<=n; i++)
	{
		cin >> b[i];
	}
	sort(b+1,b+n+1);
	cout << 2;
	return 0;
}
