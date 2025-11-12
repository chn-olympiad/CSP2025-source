#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,p[12][12];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int r=a[1];
    sort(a+1,a+1+n*m);
    reverse(a+1,a+1+n*m);
    int pos;
    for(int i=1;i<=n*m;i++)
        if(a[i]==r)
        {
            pos=i;
            break;
        }
    int cnt=0;
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
        {
            for(int i=1;i<=n;i++)
            {
                cnt++;
                p[i][j]=cnt;
                if(cnt==pos)
                {
                    cout<<j<<" "<<i;
                    break;
                }
            }
        }
        else if(j%2==0)
        {
            for(int i=n;i>=1;i--)
            {
                cnt++;
                p[i][j]=cnt;
                if(cnt==pos)
                {
                    cout<<j<<" "<<i;
                    break;
                }
            }
        }
    }
    return 0;
}
