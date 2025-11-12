#include <bits/stdc++.h>
using namespace std;
#define N 100005
char s;
int n,m;
int x[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int j=1;j<=n;j++)
	{
		if(x[j]==0)  break;
		else
		{
			while(j)
			{
				for(int k=1;k<=n;k++)
				{
					cout<<x[j]<<endl;
				}
			}
	}
    }
    cout<<x[N-1]<<endl;
    return 0;
    }
