#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s[100000],bianhao,h,l,f;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>s[i];
        f=s[1];
    }
    sort(s+1,s+1+n*m);
    for(int i=1;i<=n*m;i++)
    {
        if(f==s[i])
        {
            bianhao=n*m+1-i;
        }
    }
    if(bianhao%n==0)l=bianhao/n;
    else l=(bianhao/n)+1;
    if(l%2==0)
    {
       h=n-(bianhao-(l-1)*n)+1;
    }
    else
    {
        if(bianhao<=n)h=bianhao;
        else h=bianhao-(l-1)*n;
    }
    cout<<l<<" "<<h;
    return 0;
}
