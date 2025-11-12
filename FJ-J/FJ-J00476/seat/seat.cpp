#include<bits/stdc++.h>
using namespace std;
int n,m,g[225],x,y,s,gr,a[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++)
	{
		cin>>g[i];
	}
	gr=g[1];
	sort(g+1,g+s+1,cmp);
	for(int i=1;i<=s;i++)
	{
		if(g[i]==gr)
		{
			if(i%n==0) 
			{
				if((i/n)%2==1) cout<<i/n<<" "<<n;
				else             cout<<i/n<<" "<<1;
			}
			else
			{
				if((i/n+1)%2==1) cout<<i/n+1<<" "<<i%n;
				else       cout<<i/n+1<<" "<<n-i%n+1;
			}	
		}
		
	}
	

	return 0;
}

