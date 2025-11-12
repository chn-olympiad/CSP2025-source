#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,f,cnt=0,tt;
	cin>>n>>m;
	cin>>f;
	t=m*n-1;
	for(int i=1;i<=t;i++)
	{
		cin>>tt;
		if(tt>f) cnt++;
	}
	cnt++;
	cout<<ceil(cnt*1.0/n)<<' ';
	if((int)ceil(cnt*1.0/n)%2)
	{
		cout<<(cnt-1)%n+1;
	}
	else
	{
		cout<<n-(cnt-1)%n;
	}
	return 0;
}

