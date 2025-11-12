#include<bits/stdc++.h>
using namespace std;
bool px(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[101];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    if(n==1&&m==1)
    {
        cout<<1<<" "<<1;
    }
    int r=a[1],mc=1;
    sort(a+1,a+1+n*m,px);
    if(n==1&&m<=10)
    {
        cout<<1<<" ";
        for(int i=1;i<=m;i++)
        {
            if(a[i]!=r)
                {mc++;}
            else cout<<mc;
        }
    }
    return 0;
}
