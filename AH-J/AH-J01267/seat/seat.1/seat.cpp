#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1001],z;
    cin>>n>>m;
    cin>>z;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int c,p=n*m;
    sort(a+2,a+p+1);
    for(int i=2;i<=n*m;i++)
    {
        if(a[i]<z)
        {
            c=i;
            c=p-c;
            break;
        }
    }
	cout<<c/m+1;
	cout<<' ';
	if((c/m)%2==1)cout<<c%m;
	else cout<<m-c%m;
    return 0;
}
