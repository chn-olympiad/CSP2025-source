#include<bits/stdc++.h>
using namespace std;
struct sss
{
    int f;
    int id;
}a[105];
bool cmp(sss x,sss y)
{
    return x.f>y.f;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    a[1].id=1;
    int s=n*m;
    for(int i=1;i<=s;i++)
    {
        cin>>a[i].f;
    }
    sort(a+1,a+1+s,cmp);
    int x=0,y=0,len=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1,jj=n;j<=n;j++,jj--)
        {
            if(i%2==1)
            {
                if(a[len].id==1)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
            else
            {
                if(a[len].id==1)
                {
                    cout<<i<<" "<<jj;
                    return 0;
                }
            }
            len++;
        }
    }
    return 0;
}
