#include<bits/stdc++.h>
using namespace std;
bool cmp(int e,int b)
{
	return e>b;
}
int n,m,a[100005],g=0,sum,su=1,u;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	g=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==g)
		{
			sum=i;
		}
	}
	u=sum;
	while(sum>n)
	{
		sum-=n;
		su++;
	}
	cout<<su<<" ";
	if(su%2==0)
	{
		cout<<n-(u-(su-1)*n)+1;
	}
	else
	{
		cout<<u-(su-1)*n;
	}
	return 0;
}

