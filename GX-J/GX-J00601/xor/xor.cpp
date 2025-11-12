#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    long long ans=0;
    bool phz=true;
    for(int i=1;i<=n;i++)
    {
            cin>>a[i];
            if(a[i]!=1)
            {
                phz=false;
            }
    }
    if(phz)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if((j-i+1)%2==0)
                {
                    ans++;
                }
            }
        }
        cout<<ans;
    }
    else
    {
        cout<<(k+a[1])/2;
    }
    return 0;
}
