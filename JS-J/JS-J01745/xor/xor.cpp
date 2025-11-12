#include<bits/stdc++.h>
using namespace std;

const int x=5*1e5;
int n,k,a[x],ans;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
       cin>>a[i];

           if(a[i]==k)
           {ans++;
           a[i]=-1;}

    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1)
        {
            cnt=0;
             continue;
        }
        else
        {

            cnt+=a[i];
        }
        if(cnt%k==0&&cnt!=0)
        {
            ans++;
            cnt=0;
        }
    }

    cout<<ans;

    return 0;
}
