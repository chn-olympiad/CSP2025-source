#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    int j;
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(x==a[i])
        {
            j=i;
        }
    }
    int l=j/n+1;
    if(j%n==0) l--;
    cout<<l<<' ';
    int ch=j%n;
    if(ch==0) ch=n;
    if(l%2==1)
    {
        cout<<ch;
    }
    else
    {
        cout<<n-ch+1;
    }
    return 0;
}
