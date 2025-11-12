#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[110],sum;
bool cmp(int u,int v)
{
	return u>v;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    sum=n*m;
    for(int i=1;i<=sum;i++)
    {
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==tmp)
		{
			x=i;
			break;
		}
	}
	cout<<((x-1)/n+1)<<' ';
	if((int)((x-1)/n+1)%2==0)
	{
		cout<<n+1-((int)(x-1)%n+1);
	}else{
		cout<<(int)(x-1)%n+1;
	}
    return 0;
}
