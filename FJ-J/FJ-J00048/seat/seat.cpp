#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],s,t=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(i==1&&j==1)s=a[i][j];
			else
			{
				if(a[i][j]>s)t++;
			}
		}
	}
	int s1=t/n,s2=t%n;
//	cout<<s1<<' '<<s2<<endl;
	if(s2==0)
	{
		if(s1%2)cout<<s1<<' '<<n;
		else cout<<s1<<' '<<1;
	}
	else
	{
		s1++;
		if(s1%2)cout<<s1<<' '<<s2;
		else cout<<s1<<' '<<n-s2+1;
	}
	return 0;
}

