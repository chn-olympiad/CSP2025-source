#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool lmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>a[1];
    int t=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,lmp);
    int p;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t)
        {
            p=i;
        }
    }
    if(p%(n*2)==0)
        cout<<p/n<<" "<<1;
    else if(p%(n*2)<n)
        cout<<p/n+1<<" "<<p%(n*2);
    else if(p%(n*2)==n)
        cout<<p/n<<" "<<p%(n*2);
    else
        cout<<p/n+1<<" "<<n+1-((p%(n*2))%n);
    return 0;
}
