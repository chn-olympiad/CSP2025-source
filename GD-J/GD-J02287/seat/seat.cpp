#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,m;
ll a[N];
bool cmp(ll x,ll y)
{
	return x>y;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ll po=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
    	if(po==a[i])
    	{
    		ll x=i%(n*2),y=i/n;
    		if(x>n) 
			{
				for(int i=n+1,j=n;i<=n*2,j>=1;i++)
    			{
    				if(i==x)
    				{
    					x=j;
    					break;
					}
				}
			}	
    		if(i%n!=0)y++;
    		cout<<y<<" "<<x;
    		return 0;
		}
	}
	return 0;
}

