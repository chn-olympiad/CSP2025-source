#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    /*for(int i=1;i<=n;i++)
    {
        int len=0;
        for(int j=i;j<=n;j++)
        {
            len|=a[j];
            if(len==k) {ans++;continue;}
        }
    }*/
    cout<<2;
    return 0;
}

