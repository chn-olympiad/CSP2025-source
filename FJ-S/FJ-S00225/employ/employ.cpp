#include<bits/stdc++.h>
using namespace std;
char a[501],c[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	long long n,m,cnt=0;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			cnt++;
		}
	}
	if(cnt<m)
	{
		cout<<0;
		return 0;
	}
	else{
		cout<<1;
		return 0;
	}
} 

