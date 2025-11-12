#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[101],f[101];
    int b,c,d,e,q,w;
    cin>>b>>c;
    d=b*c;
    for(int i=1;i<=d;i++)
    {
        cin>>a[i];
    }
    e=a[1];
    sort(a,a+1,a+d+1);
    int j=d;
    for(int i=1;i<=d;i++)
    {
        f[j]=a[i];
    }
    q=e/c;
    w=e%c;
    cout<<q;
    if(q%2==0)
    {
        cout<<b-w;
    }
    else
    {
        cout<<w;
    }
    return 0;
}
