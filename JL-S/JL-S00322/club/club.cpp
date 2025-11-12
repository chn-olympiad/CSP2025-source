#include <bits/stdc++.h>
using namespace std;
#define N 10010
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,myd;
	cin>>n;
	int d;
	cin>>d;
	for(int i=0;i<=n;i++)
	{
		int d[i]={1,2,3};
		cin>>d[i];	
	}	
		for(int j=0;j<=3;j++)
		{
			myd++;
		}
			for(int i=0;i<=n;i++)
			{
				int zdz=0;
				if(myd<zdz)
				{
					cout<<zdz<<endl;
				}
				else
				{
					cout<<myd<<endl;
				}
			}
	return 0;
}
