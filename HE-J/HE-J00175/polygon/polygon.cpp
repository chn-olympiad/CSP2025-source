#include<bits/stdc++.h>
using namespace std;
int n,a[5001],i,num=0,x=0,maxx=0,k;
int ff()
{
	if(x>maxx*2) return 1;
	else return 0;
}
void f(int i)
{
	if(i>n)
	{
			
		return ;
	}
	else
	{
		x+=a[i];
		k++;
		if(a[i]>maxx) maxx=a[i];
		if(ff()&&i>=3) num++;
		maxx=0;
		if(k<=n) f(i+1);
		x-=a[i];
		k--;
		f(i+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f(1);
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
