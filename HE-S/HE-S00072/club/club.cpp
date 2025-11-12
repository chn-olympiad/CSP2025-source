#include<bits/stdc++.h>
using namespace std;
int n,b=3,m=0,x;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	if(n%2==0)
	{ 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(m<=n/2)
				{
					m=i*j;
				}else{
					break;
				}
			}
		}
		cout<<m<<endl;
	}else{
		cout<<" "<<endl;
	}
		return 0;
}
