#include <bits/stdc++.h>
using namespace std;
int n,m;
int o=0;
int a[101];
int b[101];
int t=0,s=0,r=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(a[j]>t)
			{
				t=a[j];
				s=j;
			}
		}
		if(s==1)
		{
			r=i;
		}
		b[i]=t;
		a[s]=0;
		t=0;
	}
	for(int i=1;i<=m;i++)
	{
	    if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                o+=1;
                if(o==r)
                {
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                o+=1;
                if(o==r)
                {
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
	}
	return 0;
}
