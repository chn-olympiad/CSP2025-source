#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	int R,RR;
	R=s[1];
	sort(s+1,s+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]==R)
		{
			RR=n*m-i+1;
			break;
		}
	}

	int P;
	if(RR%n==0)
	{
		P=RR/n;
	}
	else
	{
		P=RR/n+1;	
	}
//	cout<<RR<<" ";
	cout<<P<<" ";
	
	if(P%2==0)
	{
		if(RR%n==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n-(RR%n)+1;
		}
	}
	else
	{
		if(RR%n==0)
		{
			cout<<n;
		}
		else
		{
			cout<<RR%n;
		}
	}
	return 0;
} 