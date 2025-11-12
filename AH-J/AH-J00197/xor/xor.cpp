#include<bits/stdc++.h>
using namespace std;
int a[500005],qzh[500005],ans=0,n,k;
void fg(int l,int r,int dep)
{
    for(int i=1;i<=r-l+1;i++)
    {
        for(int j=l;j+i-1<=r;j++)
        {
            if((qzh[j+i-1]^qzh[j-1]) ==k)
            {
             //   cout<<j<<" "<<j+i-1<<endl;
                ans++;
                fg(l,j-1,dep+1);
                fg(j+i,r,dep+1);
                return ;
            }
        }
    }
    return ;
}
int main(void)
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        qzh[i]=qzh[i-1]^a[i];
    }
    fg(1,n,1);
    cout<<ans<<endl;
    return 0;
}
