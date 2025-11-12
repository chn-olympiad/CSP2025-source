#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b,bm;
bool cmp(int b,int c)
{
    return b>c;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>b;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+2,a+(n*m)+1,cmp);
    if(a[2]<b)
    {
        cout<<1<<" "<<1;
        return 0;
    }
    for(int i=2;i<n*m;i++)
    {
        if(b<a[i]&&a[i+1]<b)
        {
            bm=i;
        }
    }
    int lie=0,hang=0;
    if(bm%n==0)
        lie=bm/n;
    else{
        lie=bm/n+1;
    }
    bm-=((lie-1)*n);
    if(lie%2==0)
    {
        hang=(bm+(m-bm));
    }
    else{
        hang=bm;
    }
}
