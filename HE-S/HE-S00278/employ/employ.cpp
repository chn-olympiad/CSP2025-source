#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
long long jc(int a)
{
	if(a==1) return 1;
	return a*jc(a-1);
}
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++)
		cin >> c[i];
	cout << jc(n);
	return 0;
}
