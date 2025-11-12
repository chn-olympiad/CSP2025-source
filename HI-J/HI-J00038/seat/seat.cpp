#include<bits/stdc++.h>
using namespace std;

bool a[100];

int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);

	int n,m;    cin>>n>>m;

	int flag,b;
	for(int i=0;i<n*m;i++)
	{
		cin>>b;
		a[b]=1;
		if(i+1==n*m) flag=b;
	}

	int cnt=1;
	for(int i=100;i>=0;i--)
	{
		if(a[i])
		{
			if(i==flag)
			{
				if(cnt%2) cout<<cnt/m<<" "<<cnt%m+1;
				else cout<<cnt/m<<" "<<m-cnt%m;
				break;
			}
			else cnt++;
		}
	}
	
 	return 0;
}

