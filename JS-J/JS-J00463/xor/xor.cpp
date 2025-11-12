//10pts
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500003];
int one,zero;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    
    cout<<(1 xor 0)<<endl;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            one++;
        if(a[i]==0)
            zero++;
    }

    if(n<=1)
    {
        cout<<0;
        return 0;
    }   
    if(k==0)
    {
        if(one%2==0)
        {
            cout<<n;
            return 0;
        }
        if(one%2==1)
        {
            cout<<n-1;
            return 0;
        }
    }
    if(k==1)
    {
        if(one%2==1)
        {
            cout<<n;
            return 0;
        }
        if(one%2==0)
        {
            cout<<n-1;
            return 0;
        }
    }
    
    cout<<1;
    return 0;
}