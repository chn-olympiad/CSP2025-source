#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s,ma;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ma=n;
	for(int i=n;i>=1;i--)
	{
		int x=a[i];
		if(x==k)
		{
			s++;
//			cout<<i<<' '<<i<<'\n';
			ma=i-1;
			continue;
		}
		for(int j=i+1;j<=ma;j++)
		{
			x^=a[j];
			if(x==k)
			{
				s++;
//				cout<<i<<' '<<j<<'\n';
				ma=i-1;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/