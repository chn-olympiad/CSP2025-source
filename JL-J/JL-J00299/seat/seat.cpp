#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n*m;i++) cin>>a[i];
    int t=a[0],tmp;
    sort(a,a+n*m,cmp);
    for (int i=0;i<n*m;i++)
        if (a[i]==t)
        {
            tmp=i+1;
            break;
        }
    if (tmp<=n)
    {
        cout<<1<<" "<<tmp;
        return 0;
    }
    int k=tmp/n;
    if (tmp%n!=0)   k++;
    cout<<k<<" ";
    if (k%2==0)
    {
        if (tmp%n==0)   cout<<1;
        else cout<<n-(tmp%n)+1;
    }
    else
    {
        if (tmp%n==0)   cout<<n;
        else cout<<tmp%n;
    }
    return 0;
}
