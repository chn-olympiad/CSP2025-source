#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500003];
bool A=1,B=1;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1){A=0;}
        if((a[i]!=1)&&a[i]!=0){B=0;}
    }
    if(A)
    {
        if(n<=2){
            cout<<1<<endl;
        }
        else
        {
            cout<<n/2<<endl;
        }
        return 0;
    }
    if(B){
        if(k==0)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)ans++;
            }
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1 && a[i+1]==1)
                {
                    ans++;
                    i++;
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            int ans=0;
            for(int i=2;i<=n;i++)
            {
                if(a[i]!=a[i-1])
                {
                    ans++;
                        i++;
                }
                else
                {
                    continue;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
