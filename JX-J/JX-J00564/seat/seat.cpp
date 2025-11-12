#include <bits/stdc++.h>
using namespace std;
int n,m;
int st[200];
bool compare(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>st[i];
	int rstd=st[1],rr;
	sort(st+1,st+n*m+1,compare);
	for(int i=1;i<=n*m;i++)
	{
		if(st[i]==rstd)
		{
			rr=i;
			break;
		}	
	}
	int rline,rhang;
	if(rr%n==0) rline=rr/n;
	else rline=(rr/n)+1;
	if(rline%2==1) 
	{
		if(rr%n==0) rhang=n;
		else rhang=rr%n;
	}
	else{
		if(rr%n==0) rhang=1;
		else rhang=n-rr%n+1;
 	}
 	cout<<rline<<" "<<rhang;
	return 0;
}
