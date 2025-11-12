#include<bits/stdc++.h>
using namespace std;
int n,m,rr;
int xx,yy;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	rr=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=m;i>=1;i--)
	{
		if(rr>=a[(i-1)*n+1]&&rr<=a[i*n])
		{
			xx=1-(i-m);
			int hh=(1-(i-m))%2;
			for(int j=((i-1)*n+1);j<=(i*n);j++)
			{
				yy+=1;
				if(a[j]==rr)
				{
					if(hh==0)
					{
						break;
					}
					else if(hh==1)
					{
						yy=n-yy+1;
						break;
					}
				}
			}
		}
		else
			continue;
	}
	cout<<xx<<" "<<yy;
	return 0;
}
