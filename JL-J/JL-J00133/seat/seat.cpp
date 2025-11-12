#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
bool cmp(int q,int w)
{
    return q>w;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>a[1];
    int u=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    int x=1,y=0;
    for(int i=1;i<=n*m;i++)
    {
        if(x%2==1)
        {
            if(y!=n) y++;
            else x++;
        }
        else
        {
            if(y!=1) y--;
            else x++;
        }
        if(a[i]==u) cout<<x<<" "<<y;
    }
    return 0;
}
