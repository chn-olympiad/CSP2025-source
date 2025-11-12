#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn],n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int k=a[1];
    int t=n*m;
    sort(a+1,a+t+1);
    int ret=0;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==k)
        {
            ret=i;

        }
    }
    ret=n*m-ret+1;
    int ansl=ret/n;
    if(ret%n!=0)
        ansl++;
    int ansr=0;
    if(ansl%2==0)
    {
        if(ret%n==1)
            ansr=n;
        else
            ansr=(n-(ret%n)+1)%n;
    }
    else
    {
        if(ret%n==0)
            ansr=n;
        else
            ansr=ret%n;
    }
    cout<<ansl<<" "<<ansr;
    return 0;
}
