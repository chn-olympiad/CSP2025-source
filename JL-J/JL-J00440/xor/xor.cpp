#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,t=0,m=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    if(k==0)
    {
        for(int i=2;i<=n;i+=2)
        {
            t+=n-i+1;
        }
    }
    if(k==1)
    {
        m=n;
        for(int i=1;i<=n;i+=2)
        {
            t+=m;
            m/=2;
        }
    }
    cout<<t;
    return 0;
}
