#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[1001],b[1001],k,s=0,q=0;
bool cmp(int x,int y)
{
    return x<y;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>k;
    x=n-1;
    while(k!=0)
    {
        a[x]=k%10;
        k/=10;
        x--;
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(b,b+n,cmp);
    while(q<=2000000000)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                s++;
            }
            if(s<b[i])
            {
                x++;
            }
        }
        if(x==m)
        {
            c++;
        }
        q++;
    }
    cout<<c;
    return 0;
}
