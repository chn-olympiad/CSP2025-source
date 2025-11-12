#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long sum=n*m;
	int R,a,qian=1;
	cin>>R;
	for(long long i=1;i<sum;i++)
	{
		cin>>a;
		if(a>R)
		qian++;
	}
	int hang=0,lie=1,dang=1;
	while(qian--)
	{
		hang+=dang;
		if(dang==-1&&hang==0)
		{
			lie++;
			hang++;
			dang=1;
		}
		if(dang==1&&hang==n+1)
		{
			lie++;
			hang--;
			dang=-1;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
