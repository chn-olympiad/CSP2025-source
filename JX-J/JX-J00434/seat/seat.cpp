#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],s[103][103],k,num,xr;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    xr=a[1];
    sort(a+1,a+1+k);
    for(int i=m;i>=1;i--)
    {
        if(i%2==1)
        {
            for(int j=n;j>=1;j--)
            {
                num++;
                s[i][j]=a[num];
                if(s[i][j]==xr)
                {
                    cout<<i<<" "<<j;
                }
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                num++;
                s[i][j]=a[num];
                if(s[i][j]==xr)
                {
                    cout<<i<<" "<<j;
                }
            }
        }
    }
}
