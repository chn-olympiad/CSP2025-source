#include<bits/stdc++.h>
using namespace std;
int a[1010],t,f;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ma=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>ma)
                ma=a[i];
            t+=a[i];
        }
        if(t>ma*2)
        {
            cout<<"1";
            return 0;
        }
        else
        {
            cout<<"0";
            return 0;
        }
    }
    return 0;
}
