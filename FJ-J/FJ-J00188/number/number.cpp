#include <bits/stdc++.h>
using namespace std;

const int S=1e6+5;

int a[S];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char c;
	int t=0;
	while(cin>>c)
	{
		int m=c-'0';
		if (m>=0&&m<=9) 
		{
			a[++t]=m;
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
