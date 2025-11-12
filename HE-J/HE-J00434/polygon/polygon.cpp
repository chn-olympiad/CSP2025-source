#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ca,x,t,maxx;
void doing(int i)
{
	int mm=0;
	if(x>maxx*2&&ca>=3)t++;
	if(i>n)	return;
	else
	{
		x+=a[i];
		ca++;
		if(maxx<a[i]){mm=maxx;maxx=a[i];}
		if(i<=n)doing(i+1);
		x-=a[i];
		ca--;
		if(maxx==a[i])maxx=mm;
		doing(i+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	doing(1);
	cout<<t-2;  
	fclose(stdin);
	fclose(stdout);
	return 0;
}
