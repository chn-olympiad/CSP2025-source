#include<bits/stdc++.h>
using namespace std;
int n,m,fs[1010],dy,h=1,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>fs[i];
		if(fs[i]>fs[1])
		{
			dy++;
		}
	}
	h+=(dy/n);
	cout<<h;
	if(h%2==0)
	{
		l=dy%n;
		l--;
		cout<<" "<<(n-l-1);
	}
	else
	{
		l=dy%n;
		cout<<" "<<l+1;
	}
	return 0;
}