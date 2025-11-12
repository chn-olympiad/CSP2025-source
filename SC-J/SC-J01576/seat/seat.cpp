#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],n,m,f,num;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==f)
		{
			num=i;
			break;
		}
	}
	int nx,ny;
	nx=(num+n-1)/n;
	if(nx%2==1)
	{
		if(num%n==0) ny=n;
		else{
			ny=num%n;	
		}
	}
	else{
		if(num%n==0) ny=1;
		else{
			ny=n-num%n+1;
		}
	}
	cout<<nx<<' '<<ny;
	fclose(stdin);
	fclose(stdout);
	return 0;
}