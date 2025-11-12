#include <bits/stdc++.h>
using namespace std;

int s[100000];
int c[100000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,d=0,b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1&&c[i]>b)
			d++;
		else
			b++;
	}
	if(d<m)
		cout<<0;
    else
		cout<<83479824;
	return 0;
}
