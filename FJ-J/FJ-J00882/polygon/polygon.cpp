#include<bits/stdc++.h>
using namespace std;
int n;
int s[5005];
void dbx()
{
	if(n<=3)
	{
		if(s[1]+s[2]+s[3]>2*max(s[1],max(s[2],s[3])))
		{
			cout<< 1;
			return ;
		}
		cout<< 0;
		return ;
	}
	cout<<n-2;
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> s[i];
	}
	dbx();
	return 0;
}
