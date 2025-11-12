#include <bits/stdc++.h>
using namespace std;
int n,m,xd,xp;
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n*m+10);
    cin>>xd;
    a[1]=xd;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n*m;i++)
    {
        if(xd==a[i])
        {
            xp=i;
        }
    }
    xp+=1;
    int x=xp%n,y=ceil((xp*1.0)/(m*1.0));
    cout<<y<<" ";
    if(y%2==1)
    {
		if(x==0)
		{
			cout<<n<<"\n";
		}
		else
		{
			cout<<x<<"\n";
		}
	}
    else
    {
		if(x==0)
		{
			cout<<1<<"\n";
		}
		else
		{
			cout<<n-x+1<<"\n";
		}
	}
    return 0;
}
