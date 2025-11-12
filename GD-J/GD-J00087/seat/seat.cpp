#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}
int n,m,a[1001],fs,l,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	fs=a[1],l=1;
	sort(a+1,a+1+n*m,cmp);//从大到小 
	for(int i=1;i<=n;i++)//l
	{
		if(a[i*m]<=fs)
		{
			l=i;
			break;
		}
	}
	cout<<l<<" ";
	for(int i=(l-1)*m+1;i<=l*m;i++)
	{
		if(a[i]==fs)
		{
			cout<<i-(l-1)*m;
			break;
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/ 
