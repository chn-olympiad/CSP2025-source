#include <bits/stdc++.h>
using namespace std;
int n,m,res;
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    res=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt=0,m2=1,tmp=1;
    for(int i=1;i<=n*m;i++)
    {
        int n2;
        if(cnt==n)
        {
            m2++;
            cnt=0;
            if(tmp==1)
                tmp=0;
            else
                tmp=1;
        }
        cnt++;
        if(tmp==1)
            n2=cnt;
        else
            n2=n-cnt+1;
        if(a[i]==res)
            cout<<m2<<" "<<n2;
    }
    return 0;
}
