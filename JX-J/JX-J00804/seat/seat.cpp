#include<bits/stdc++.h>
using namespace std;
int n,m,s[10000],a;
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++)
    {
        if(i==1)
        {
            cin>>a;
            s[i]=a;
        }
        else
        {
            cin>>s[i];
        }
    }
    sort(s+1,s+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(s[i]==a)
        {
            if(i%n==0)
            {
                cout<<i/n<<" "<<m;
            }
            else
            {
                cout<<i/n+1<<" "<<i%n;
            }
        }
    }
    return 0;
}
