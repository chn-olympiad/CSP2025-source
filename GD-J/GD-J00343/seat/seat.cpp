#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=150;

int n,m,c,r,tot;
int u;
int a[N];

bool cmp(int x,int y)
{
	return x>y;
	
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	cin>>n>>m;//ÐÐ,ÁÐ 
    tot=n*m;
    for(int i=1;i<=tot;i++)
    {
    	cin>>a[i];
	}
	
	u=a[1];
	
	sort(a+1,a+tot+1,cmp);
	
	for(int i=1;i<=tot;i++)
	{
		if(a[i]==u)
		{
			if(i%n==0)
			c=i/n;
			else
			c=i/n+1;
			
			if(c%2==1)
			{
				if(i%n==0) r=n;
				else r=i%n;
			}
			else
			{
				if(i%n==1) r=n;
				else
				{
					if(i%n!=0)
					r=n-i%n+1;
					if(i%n==0)
					r=1;
				} 
			}
			
			cout<<c<<" "<<r<<"\n";
			return 0;
		}
	}
	
	return 0;
}
