#include <bits/stdc++.h>
using namespace std;
int a[110];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int l=a[1],idx;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==l)
		{
			idx=i;
		}
	}
	if(idx%m!=0)
	{
		cout<<idx/m+1<<" ";
		if((idx/m+1)%2==0)
		{
			if(idx%n==0)
			{
				cout<<1;
			}
			else
			{
				cout<<(n-idx%n)+1;
			}
		}
		else
		{
			if(idx%n==0)
			{
				cout<<idx;
			}
			else
			{
				cout<<idx%n;
			}
		}
	}
	else
	{
		cout<<idx/m<<" ";
		if((idx/m)%2==0)
		{
			if(idx%n==0)
			{
				cout<<1;
			}
			else
			{
				cout<<(n-idx%n)+1;
			}
		}
		else
		{
			if(idx%n==0)
			{
				cout<<idx;
			}
			else
			{
				cout<<idx%n;
			}
		}
	}
	/*
		wo bang bian you ge chi bo xiao hai gei WOW  
		wo zhe tai ji zi ze meng da bu liao zhong wen,wo yao da zhong wen!zhong wen!Chinese!
		da ping yin hao lei 
		xiao hai gei hai da le yi ge jing tian da ge ,hao chou 
		wo mei zhao le
		wo tiao chu yu fa cuo wu le ,wo you you zhao le ,hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
		san zhong de ji zi hao lao a,an jian wo duo kuai an bu dong le 
	*/
	return 0;
}
