#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,rs,rm,rm_1,rn_1,rn;
    cin>>m>>n;
    cin>>rs;
    int a[m*n+5];
    int st[m+5][n+5];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) st[i][j]=0;
    for(int i=2;i<=m*n;i++) cin>>a[i];
    a[1] =rs;
    sort(a+1,a+m*n+1);
    int t=m*n+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            t--;
            st[j][i]=a[t];
            if(a[t]==rs)
            {
                rm_1=j;
                rn_1=i;
            }
        }
    }
    if(rn_1%2==0) rm=m-rm_1+1;
    else rm=rm_1;
    rn=rn_1;
    cout<<rn<<" "<<rm;
    return 0;
}
