#include<bits/stdc++.h>
using namespace std;
int n,a[105],r,w,m,s;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    s=n*m;
    for(int i=1;i<=s;i++)
    {
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+s+1);
    for(int i=1;i<=s;i++)
    {
        if(r==a[i])
        {
            r=s-i+1;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            for(int j=m;j>=1;j--)
            {
                w++;
                if(r==w)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
                w++;
                if(r==w)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }

	return 0;
}
