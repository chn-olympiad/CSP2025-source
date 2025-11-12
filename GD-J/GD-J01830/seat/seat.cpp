#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],b[110],sum=0,c=1,r=1;
bool flag=true;
bool cmp(int a1,int b1)
{
	return a1>b1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long s=n*m;
	for(int i=1;i<=s;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+s,cmp);
	cout<<endl;
	for(int i=1;;i++)
	{
		if(b[i]==a[1])break;
		sum++;
	}
	for(int i=1;i<=sum;i++)
	{
		if(flag)r++;
		if(!flag)r--;
		if(r>=m&&i+1<=sum)c++,i++,flag=false;
		if(r<=1&&c>1&&i+1<=sum)c++,i++,flag=true;
	}
	cout<<c<<" "<<r;
	return 0;
}
