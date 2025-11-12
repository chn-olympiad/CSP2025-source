#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000;
int n,m,a[N];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p){
			p=i;
			break;
		}
	}
	int y=0;
	if(p%n==0)
	{
		y=p/n;
		cout<<p/n<<" ";
	} 
	else
	{
		y=ceil(p*1.0/n);
		cout<<ceil(p*1.0/n)<<" ";
	}
	if(y%2==1)
	{
		if(p%n!=0)
		{
			cout<<p%n;
		}
		else cout<<n;
	}
	else if(y%2==0)
	{
		if(p%n!=0)
		{
			cout<<n-p%n+1;
		}
		else if(p%n==0)
		{
			cout<<1;
		}
	}
	return 0;
}
