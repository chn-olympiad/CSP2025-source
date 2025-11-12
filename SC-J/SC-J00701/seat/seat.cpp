#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long x,y,s[N],a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++)
	{
		cin>>s[i];
	}
	a=s[1];
	for(int i=1;i<=x*y;i++)
	{
		for(int j=i+1;j<=x*y;j++)
		{
			if(s[i]<s[j])
			{
				swap(s[i],s[j]);
			}
		}
	} 
	for(int i=1;i<=x*y;i++)
	{
		if(s[i]==a)
		{
			a=i;
			break;
		}
	}
	cout<<(a+x-1)/x<<' ';
	if(((a+x-1)/x)%2==0)
	{
		if(a%x==0)
		{
			cout<<1;
		}
		else
		{
			cout<<a+x-1-a/x*x;
		}
	}
	else
	{
		if(a%x==0)
		{
			cout<<x; 
		}
		else
		{
			cout<<a%x;
		}
	}
	return 0;
}