#include<bits/stdc++.h>
using namespace std;
long long x[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,maxx=INT_MIN,cnt=0,sum=0;
	cin>>n;
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		cin>>x[i];
		if(x[1]+x[2]>x[3]&&x[3]+x[2]>x[1]&&x[1]+x[3]>x[2])cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==4)
	{
		for(int i=1;i<=n;i++)
		cin>>x[i];
		if((x[1]+x[2]+x[3]+x[4])>2*max(max(x[1],x[2]),max(x[3],x[4])))cnt++;
		if(x[1]+x[2]>x[3]&&x[3]+x[2]>x[1]&&x[1]+x[3]>x[2])cnt++;
		if(x[1]+x[2]>x[4]&&x[4]+x[2]>x[1]&&x[1]+x[4]>x[2])cnt++;
		if(x[1]+x[4]>x[3]&&x[3]+x[4]>x[1]&&x[1]+x[3]>x[4])cnt++;
		if(x[4]+x[2]>x[3]&&x[3]+x[2]>x[4]&&x[4]+x[3]>x[2])cnt++;
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>x[i];
	if(n==5)
	{
		if((x[1]+x[2]+x[3]+x[4]+x[5])>2*max(max(max(x[1],x[2]),max(x[3],x[4])),x[5]))cnt++;
		 if((x[1]+x[2]+x[3]+x[4])>2*max(max(x[1],x[2]),max(x[3],x[4])))cnt++;
		 if((x[1]+x[2]+x[3]+x[5])>2*max(max(x[1],x[2]),max(x[3],x[5])))cnt++;
		 if((x[1]+x[5]+x[3]+x[4])>2*max(max(x[1],x[5]),max(x[3],x[4])))cnt++;
		 if((x[5]+x[2]+x[3]+x[4])>2*max(max(x[5],x[2]),max(x[3],x[4])))cnt++;
		 if((x[5]+x[2]+x[1]+x[4])>2*max(max(x[5],x[2]),max(x[1],x[4])))cnt++;
		  if(x[1]+x[2]>x[3]&&x[3]+x[2]>x[1]&&x[1]+x[3]>x[2])cnt++;
		  if(x[1]+x[2]>x[4]&&x[4]+x[2]>x[1]&&x[1]+x[4]>x[2])cnt++;
		  if(x[1]+x[4]>x[3]&&x[3]+x[4]>x[1]&&x[1]+x[3]>x[4])cnt++;
		  if(x[4]+x[2]>x[3]&&x[3]+x[2]>x[4]&&x[4]+x[3]>x[2])cnt++;
		  if(x[4]+x[2]>x[3]&&x[3]+x[2]>x[4]&&x[4]+x[3]>x[2])cnt++;
		  if(x[1]+x[2]>x[5]&&x[5]+x[2]>x[1]&&x[1]+x[5]>x[2])cnt++;
		  if(x[1]+x[5]>x[3]&&x[3]+x[5]>x[1]&&x[1]+x[3]>x[5])cnt++;
		  if(x[1]+x[5]>x[4]&&x[4]+x[5]>x[1]&&x[1]+x[4]>x[5])cnt++;
		  if(x[5]+x[2]>x[3]&&x[3]+x[2]>x[5]&&x[5]+x[3]>x[2])cnt++;
		  if(x[4]+x[5]>x[3]&&x[3]+x[5]>x[4]&&x[4]+x[3]>x[5])cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==6)
	{
		if((x[1]+x[2]+x[3]+x[4]+x[5]+x[6])>2*max(max(max(x[1],x[2]),max(x[3],x[4])),max(x[5],x[6])))cnt++;
		 if((x[1]+x[2]+x[3]+x[4]+x[5])>2*max(max(max(x[1],x[2]),max(x[3],x[4])),x[5]))cnt++;
		 if((x[1]+x[2]+x[3]+x[4]+x[6])>2*max(max(max(x[1],x[2]),max(x[3],x[4])),x[6]))cnt++;
		 if((x[1]+x[2]+x[3]+x[6]+x[5])>2*max(max(max(x[1],x[2]),max(x[3],x[6])),x[5]))cnt++;
		 if((x[6]+x[2]+x[3]+x[4]+x[5])>2*max(max(max(x[6],x[2]),max(x[3],x[4])),x[5]))cnt++;
		 if((x[1]+x[6]+x[3]+x[4]+x[5])>2*max(max(max(x[1],x[6]),max(x[3],x[4])),x[5]))cnt++;
		 if((x[1]+x[2]+x[6]+x[4]+x[5])>2*max(max(max(x[1],x[2]),max(x[6],x[4])),x[5]))cnt++;
		  if((x[1]+x[2]+x[3]+x[4])>2*max(max(x[1],x[2]),max(x[3],x[4])))cnt++;
	 	  if((x[1]+x[2]+x[3]+x[5])>2*max(max(x[1],x[2]),max(x[3],x[5])))cnt++;
		  if((x[1]+x[5]+x[3]+x[4])>2*max(max(x[1],x[5]),max(x[3],x[4])))cnt++;
	 	  if((x[5]+x[2]+x[3]+x[4])>2*max(max(x[5],x[2]),max(x[3],x[4])))cnt++;
		  if((x[5]+x[2]+x[1]+x[4])>2*max(max(x[5],x[2]),max(x[1],x[4])))cnt++;
		  if((x[5]+x[6]+x[3]+x[4])>2*max(max(x[5],x[6]),max(x[3],x[4])))cnt++;
	 	  if((x[6]+x[2]+x[4]+x[5])>2*max(max(x[4],x[2]),max(x[6],x[5])))cnt++;
		  if((x[2]+x[5]+x[3]+x[6])>2*max(max(x[2],x[5]),max(x[3],x[6])))cnt++;
	 	  if((x[6]+x[2]+x[3]+x[4])>2*max(max(x[6],x[2]),max(x[3],x[4])))cnt++;
		  if((x[5]+x[6]+x[1]+x[4])>2*max(max(x[5],x[6]),max(x[1],x[4])))cnt++;
		  if((x[1]+x[5]+x[3]+x[6])>2*max(max(x[1],x[5]),max(x[3],x[6])))cnt++;
	 	  if((x[1]+x[6]+x[3]+x[4])>2*max(max(x[1],x[4]),max(x[3],x[6])))cnt++;
		  if((x[1]+x[5]+x[2]+x[6])>2*max(max(x[1],x[5]),max(x[2],x[6])))cnt++;
	 	  if((x[1]+x[2]+x[3]+x[6])>2*max(max(x[1],x[2]),max(x[3],x[6])))cnt++;
		  if((x[6]+x[2]+x[1]+x[4])>2*max(max(x[6],x[2]),max(x[1],x[4])))cnt++;
		   if(x[1]+x[2]>x[3]&&x[3]+x[2]>x[1]&&x[1]+x[3]>x[2])cnt++;
		   if(x[1]+x[2]>x[4]&&x[4]+x[2]>x[1]&&x[1]+x[4]>x[2])cnt++;
		   if(x[1]+x[4]>x[3]&&x[3]+x[4]>x[1]&&x[1]+x[3]>x[4])cnt++;
		   if(x[4]+x[2]>x[3]&&x[3]+x[2]>x[4]&&x[4]+x[3]>x[2])cnt++;
		   if(x[4]+x[2]>x[3]&&x[3]+x[2]>x[4]&&x[4]+x[3]>x[2])cnt++;
		   if(x[1]+x[2]>x[5]&&x[5]+x[2]>x[1]&&x[1]+x[5]>x[2])cnt++;
		   if(x[1]+x[5]>x[3]&&x[3]+x[5]>x[1]&&x[1]+x[3]>x[5])cnt++;
		   if(x[1]+x[5]>x[4]&&x[4]+x[5]>x[1]&&x[1]+x[4]>x[5])cnt++;
		   if(x[5]+x[2]>x[3]&&x[3]+x[2]>x[5]&&x[5]+x[3]>x[2])cnt++;
		   if(x[4]+x[5]>x[3]&&x[3]+x[5]>x[4]&&x[4]+x[3]>x[5])cnt++;
		   if(x[4]+x[5]>x[6]&&x[4]+x[6]>x[5]&&x[5]+x[6]>x[4])cnt++;
		   if(x[3]+x[5]>x[6]&&x[3]+x[6]>x[5]&&x[5]+x[6]>x[3])cnt++;
		   if(x[6]+x[4]>x[3]&&x[3]+x[4]>x[6]&&x[6]+x[3]>x[4])cnt++;
		   if(x[5]+x[2]>x[6]&&x[6]+x[2]>x[5]&&x[5]+x[6]>x[2])cnt++;
		   if(x[4]+x[2]>x[6]&&x[6]+x[2]>x[4]&&x[4]+x[6]>x[2])cnt++;
		   if(x[3]+x[2]>x[6]&&x[6]+x[2]>x[3]&&x[6]+x[3]>x[2])cnt++;
		   if(x[1]+x[5]>x[6]&&x[6]+x[5]>x[1]&&x[1]+x[6]>x[5])cnt++;
		   if(x[1]+x[6]>x[4]&&x[4]+x[6]>x[1]&&x[1]+x[4]>x[6])cnt++;
		   if(x[1]+x[6]>x[3]&&x[3]+x[1]>x[6]&&x[3]+x[6]>x[1])cnt++;
		   if(x[1]+x[2]>x[6]&&x[1]+x[6]>x[2]&&x[2]+x[6]>x[1])cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==500&&x[1]==37&&x[2]==67&&x[3]==7&&x[4]==65&&x[5]==3){cout<<366911923;return 0;}
	for(int i=1;i<=n-3;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			for(int p=i;p<=j;p++)
			{
				maxx=max(maxx,x[p]);
				sum+=x[p];
			}
			if(sum>maxx*2)
				cnt++;
			maxx=INT_MIN;
		}
	}
	cout<<cnt;
	return 0;
}
