#include<bits/stdc++.h>
using namespace std;
int c,r,a[101],i,j,k,l,diao,R,Rc,Rr;
int main()
{
	freopen("sent.in","r",stdin);
	freopen("sent.out","w",stdout);
	cin>>c>>r;
	for(i=1;i<=c*r;i++)
	cin>>a[i];
	R=a[1];
	for(j=2;j<=i;j++)
	{
		for(k=j-1;k>=1;k--)
		{
			if(a[j]>a[k])
			{
				diao=a[j];
				a[j]=a[k];
				a[k]=diao;
				j--;
			}
			else break;
		}
	}
	for(l=1;l<=i;l++)
	{
		if(R==a[l])
		{
			Rc=ceil(float(l)/r);
			if(Rc%2==1)
			{
				if(l%r==0)
				Rr=r;
				else Rr=l%r;
			}
			else
			{
				if(l/r==0)
				Rr=1;
				else Rr=r-l%r+1;
			}
		}
	}
	cout<<Rc<<" "<<Rr;
	return 0;
}
