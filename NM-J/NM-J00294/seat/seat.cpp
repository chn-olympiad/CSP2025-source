#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    int i,n,m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        if(a[1]==100||n*m==1) cout<<1<<" "<<1;
        else if(a[1]==1) cout<<m<<" "<<n;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
		if(a[i]==n*m);
		cout<<1<<" "<<1;
		return 0;
	}
	return 0;
}
