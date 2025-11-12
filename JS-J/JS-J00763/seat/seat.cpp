#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l,i,j,re,k=1;
	cin>>h>>l;
	cin>>b[1];
	re=b[1];
	for(i=2;i<=l*h;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+l*h+1);
	k=l*h;
	//for(i=1;i<=l*h;i++) cout<<b[i]<<" ";
	for(i=1;i<=l;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<=h;j++)
			{
				//cout<<1<<" ";
				a[j][i]=b[k];
				k--;
			}
		}
		else 
		{
			for(j=h;j>=1;j--)
			{
				//cout<<0<<" ";
				a[j][i]=b[k];
				k--;
			}
		}
	}
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=h;j++)
		{
			//cout<<a[i][j]<<" ";
			if(a[i][j]==re) cout<<j<<" "<<i;
		}
		//cout<<endl;
	}
}
