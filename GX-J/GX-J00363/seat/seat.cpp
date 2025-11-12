#include<iostream>
#include<stdio.h>
using namespace tsd;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[105],s[105];
    int c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        s[i]=a[i];
    }
    int maxn=s[1];
    for(int i=1;i<=n*m;i++)
    {
        if(s[i+1]>s[i])
        {
            zc=s[i];
            s[i]=s[i+1];
            s[i+1]=zc;
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(s[i]==a[1]){
            if(i==n){
                c=1;
                r=n;
            }
            else{
                c=2;
                r=n;
            }
        }
    }
    cout << c << " " << r << " ";
    return 0;
}
