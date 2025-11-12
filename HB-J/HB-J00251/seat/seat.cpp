#include <bits/stdc++.h>
using namespace std;
int tsy(int t,int s)
{
	return (t-1)/s+1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,max,j,x=0,c,r,h;
	int a[130]={0};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	h=a[1];
	do{
		max=0;
		for(int i=1;i<=n*m;i++)
		{
			if(max<a[i])
			{
				max=a[i];
				j=i;
			}
		}
		a[j]=0;
		x+=1;
	}while(max!=h);
	c=tsy(x,m);
	if(c%2==0)
	{
		r=m-x%m+1;
	}else{
		r=x%m;
		if(r==0)
		{
			r=m;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
