#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],b[500005],c[1000005],k,ans,l;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    c[0]=INT_MAX;
    cin>>n>>k;
    l=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1] xor a[i]; 
        if(c[k xor b[i]]!=0)
        {
            ans++;
            for(int j=l;j<=i;j++)
                c[b[j]]=0;    
            c[0]=INT_MAX;
            b[i]=0;
            l=i+1;
        }
        else    
            c[b[i]]++;
    }
    cout<<ans;
    return 0;
}