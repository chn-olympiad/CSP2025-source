#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],s,m=998244353;
long long ksm(long long x,int y)
{
	long long s=1;
	while(y)
	{
		if(y&1)
			s=(s*x)%m;
		x=(x*x)%m;
		y>>=1; 
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3)
	{
		if(n<3)
			cout<<0;
		else if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
		return 0; 
	}
	if(a[n]==1)
	{
		long long s=ksm(2ll,n);
		s-=n;
		while(s<=0)
			s+=m;
		s%=m;
		s-=(n*(n-1)/2);
		while(s<=0)
			s+=m;
		s%=m;
		s-=1;
		while(s<=0)
			s+=m;
		s%=m;
		cout<<s;
		return 0;
	}
//	if(n<=20)
//	{
	int x=1<<n,ss,l,lb,y,fl;
	x--;
	for(int i=1;i<=x;i++)
	{
		l=0,lb=0,y=i,ss=0;
		while(y)
		{
			l++;
			if(y&1)
			{
				b[++lb]=a[l];
			}
			y>>=1;
		}
		if(lb<3)
			continue;
		fl=0;
		for(int j=1;j<lb;j++)
		{
			ss+=b[j];
			if(ss>b[lb])
			{
				fl=1;
				break;
			}
		}
		if(fl)
			s++;
	}
	cout<<s;
//	}
	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/
/*
我们的征途
是星辰大海
南征北战
去亚洲之巅
一起高唱
光荣与梦想
We are Chengdu
We are Chengdu
Ale Aleo
Ale Aleo
哦哦哦
哦哦哦哦哦
一起高唱
光荣与梦想
We are Chengdu
We are Chengdu
*/ 