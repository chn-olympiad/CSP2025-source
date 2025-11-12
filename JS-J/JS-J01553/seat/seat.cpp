#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool cmp(int s,int t)
{
    return(s>=t);
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    int g=a[1];
    sort(a+1,a+k+1,cmp);
    int f;
    for(int i=1;i<=k;i++)
    {
        if(a[i]==g)
        {
            f=i;
            break;
        }
    }
    int p=f%n;
    int q=f/n;
    if(p==0)
    {
        q=q-1;
        p=n;
    }
    if(q%2==0)
    {
        q=q+1;
        cout<<q<<" "<<p<<endl;
    }
    else
    {
        q=q+1;
        p=m-p+1;
        cout<<q<<" "<<p<<endl;
    }
    return 0;
}
