#include <bits/stdc++.h>
using namespace std;
int a[100],f=0;
int q(int x)
{
    int s=0,zd=0;
    if(x==0)
        return 0;
    x--;
    for(int i=1;i<=x;i++)
    {
        cout<<a[i]<<' ';
        s+=a[i];
        zd=max(zd,a[i]);
    }
    cout<<endl;
    cout<<zd<<' '<<s<<endl<<endl;
    if(s>zd*2 && s!=0)
        cout<<"YES";
    q(x);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
       cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        q(n);
        int c=a[1];
        for(int j=1;j<=n;j++)
            a[j]=a[j+1];
        a[n]=a[1];
    }
    cout<<f;
}
