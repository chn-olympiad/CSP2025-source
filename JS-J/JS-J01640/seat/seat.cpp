#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e2+10;
int n,m;
int a[MAXN];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int num=a[1];
    int sum=0;
    for(int i=2;i<=n*m;i++)
    {
        if(a[i]>num)
        {
            sum++;
        }
    }
    cout<<sum/n+1<<' ';
    if((sum/n+1)%2==1)
    {
        cout<<sum%n+1;
    }
    else
    {
        cout<<m-(sum%n);
    }
    cout<<'\n';
    return 0;
}
