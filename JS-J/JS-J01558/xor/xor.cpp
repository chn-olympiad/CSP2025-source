#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long sum=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    long long h=-1,t;
    for(long long i=0;i<n;i++)
    {
        cin>>t;
        if(h==-1)
        {
            sum++;
            h=t;
        }
        else
        {
            h^=t;
        }
        if(h==k)
        {
            h=-1;
        }
    }
    cout<<sum;
    return 0;
}
