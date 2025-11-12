#include<bits/stdc++.h>
using namespace std;
int n,m,ans,t=0,h,l,num;
int a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ans=n*m;
	for(int i=1;i<=ans;i++)
	{
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+ans+1);
	for(int i=ans;i>=1;i--)
	{
		t++;
		if(a[i]==b)
		break;
	}
	l=t/n;
	if(t%n>0)
	l=l+1;
	if(l%2==0)
	{
		num=t%n;
		if(num==0)
		h=1;
		else
		h=n-num+1;
	}
	else
	{
		num=t%n;
		if(num==0)
		h=n;
		else
		h=num;
	}
	cout<<l<<" "<<h;
	return 0;
}
