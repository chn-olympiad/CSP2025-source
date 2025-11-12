#include<bits/stdc++.h>
using namespace std;
long long n,m,z;
struct s{
	long long a,bj;
}f[10005];
bool cmp(s x,s y)
{
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	f[1].bj=1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>f[i].a;
	}
	sort(f+1,f+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(f[i].bj==1)
		{
			z=i;
			break;
		}
	}
	cout<<(z-1)/n+1<<" ";
	if(((z-1)/n+1)%2==0)
	{
		cout<<n-z%n+1;
	}
	else
	{
		cout<<(z-1)%n+1;
	}
	return 0;
}

