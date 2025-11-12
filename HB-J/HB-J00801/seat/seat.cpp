#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[1000],x[1000];
int a[15][15];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>x[i];
    }
    int u=x[1];
    sort(x+1,x+1+n*m);
    for(int i=1;i<=n*m;i++)
    {
        s[n*m-i+1]=x[i];
    }
    int h=1,l=1;
    int cnt=0;
    while(1)
    {
        cnt++;
        a[h][l]=s[cnt];
        if(a[h][l]==u)
        {
            cout<<h<<" "<<l;
            return 0;
        }
        if(l==n&&h%2==1)
        {
            h++;
        }
        else{
            if(l==1&&h%2==0)
            {
                h++;
            }
            else
            {
                if(h%2==0) l--;
                else l++;
            }
        }
    }
    return 0;
}
