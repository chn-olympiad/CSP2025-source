#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a=n*m;
	long long b[a];
	for(long long i=1;i<=a;i++)
	{
		cin>>b[i];
	}
	long long c=b[1];
	sort(b+1,b+n+1);
	long long cnt=0;
	for(long long j=a-1;j>=0;j--)
	{
		if(b[j]==c)break;
		cnt++;
	}
	long long cnt2=0;
	long long cnt3=0;
	if(cnt%n==0)
	{
	cnt3+=cnt/n;
	cnt2+=n;	
	}
	else 
	{
	cnt3+=cnt/n+1;
	cnt2+=cnt%n;
	}
	if(cnt3%2==1)cout<<cnt3<<' '<<cnt2;
	else cout<<cnt3<<' '<<a-cnt2;
	return 0;
}
