#include<bits/stdc++.h>
using namespace std;
const int N=11;
int x,y,a[N*N],r,r1,j,k;
bool cmp(int q,int w)
{
	return q>w;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+x*y+1,cmp);
	for(int i=1;i<=x*y;i++)
	{
		if(a[i]==r)
		{
			r1=i;
			break;
		}
	}
	k=(r1-1)/x+1;
	if(k%2==0)
	{
		j=x-r1%x+1;
	}
	else if(k%2==1&&k!=1)
	{
		j=r1%x;
	}
	else if(k==1)
	{
		j=r1;
	}
	cout<<k<<' '<<j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
