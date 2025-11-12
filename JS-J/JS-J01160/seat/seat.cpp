#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn*maxn],b[maxn*maxn],p;
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	p=a[1];
	int L=n*m;
	sort(a+1,a+L+1);
	for(int i=L;i>=1;i--)
		b[L-i+1]=a[i];
	for(int i=1;i<=L;i++)
	{
		if(b[i]==p)
		{
			int k1,k2;
			double u,h1=i,h2=n;
			u=h1/h2;
			k1=ceil(u);
			if(k1%2!=0)
			{
				k2=i%n;
				if(k2==0)
					k2=n;
			}
			else
			{
				if(i%n==1)
					k2=n;
				else if(i%n==0)
					k2=1;
				else
					k2=(n+1)-(i%n);
			}
			cout<<k1<<' '<<k2;
			break;
		}
	}
	return 0;
}
