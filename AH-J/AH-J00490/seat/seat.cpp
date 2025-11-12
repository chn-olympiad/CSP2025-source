#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000000],b[100000],c[100000],id,d;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[j];
            b[j]=n;
            if(n%2==1)c[j]=ma
            else if(n%2==0)c[j]=m-j+1;
        }
    }
    d=a[1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]<a[i+1])swap(a[i],a[i+1]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==d)cout<<b[i]<<" "<<c[i];
        }
    }
    return 0;
}
