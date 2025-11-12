#include<bits/stdc++.h>
using namespace std;
int ans,n,k,a[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k==1)
    {
        for(int i=1;i<=n;i++)
            if(a[i]==1)ans++;
        cout<<ans;
        return 0;
    }
    else if(k==0)
    {
        for(int i=1;i<=n;i++)
            if(a[i]==0)ans++;
        for(int i=1;i<=n;)
        {
            if(a[i]==1 && a[i+1]==1)
            {
                ans++;
                i+=2;
            }
            else i++;
        }
        cout<<ans;
        return 0;
    }
    else cout<<0;
    return 0;
}
