#include <bits/stdc++.h>
using namespace std;
int main( )
{
	int t,n,a[10000][10000],s=-1,za=0,zb=0,zc=0,t1=0,t2=0,t3=0;
	//freopen(club.in,"r",stdin);
	//freopen(club.out,"w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(j==3)
				{
				    s=max(a[i][1],max(a[i][2],a[i][3]));
					if(a[i][1]==s&&za<=n/2)
					{
						za+=1;
                        t1+=a[i][1];
					}
					else if(a[i][2]==s&&zb<=n/2)
					{
						zb+=1;
						t1+=a[i][2];
					}
					else
					{
						zc+=1;
						t3+=a[i][3];
                    }
                }

			}
		}
        cout<<t1+t2+t3;
        t1=0;
        t2=0;
        t3=0;
	}
	return 0;

}
