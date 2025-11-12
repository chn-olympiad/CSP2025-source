#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],t,k,x,y;
bool ll(int a,int b){return a>b;}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,ll);
	x=1,y=0;
	for(int i=1;i<=n*m;i++)
	{
		if(x%2==1) y++;	
		else y--;
		if(a[i]==k) return cout<<x<<" "<<y,0;
		if(y==m&&x%2==1) 
		{
			x++;	
			i++;
			if(a[i]==k) return cout<<x<<" "<<y,0;
		}
		if(y==1&&x%2==0)
		{
			x++;	
			i++;
			if(a[i]==k) return cout<<x<<" "<<y,0;	
		}
	}
	return 0;
 } 
