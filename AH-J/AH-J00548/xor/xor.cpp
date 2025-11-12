#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ls[2000005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]^=a[i-1];
    }
    memset(ls,-1,sizeof(ls));
    ls[0]=0;
    int lt=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ls[a[i]^k]>=lt)
        {
            cnt++;
            lt=i;
        }
        ls[a[i]]=i;
    }
    cout<<cnt;
    return 0;
}
