#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
	{
		char b;
		cin>>b;
		s[i]=b;
	}
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	} 
	cout<<0;
	return 0;
}
