#include<bits/stdc++.h>
using namespace std;
int n,m,a[150];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;	
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int f=a[1],cnt=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		cnt++;
		if(f==a[i]) 
		{
			f=cnt;
			break;
		}
	}
	if(f%n!=0)
	{
		cout<<f/n+1<<" ";
		if((f/n+1)%2==1) cout<<f%n;
		else cout<<n-f%n+1;
	}
	else 
	{
		cout<<f/n<<" ";
		if((f/n)%2==1) cout<<n-f%n;
		else 
		{
			if(f%n==0) cout<<n; 
			else cout<<n-f%n+1;
		} 
		
	}
	 
	return 0;
} 