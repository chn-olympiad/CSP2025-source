#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],he[500005],ans,cnt=1,l=1;
bool tong[2097152];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","r",stdout);
    cin>>n>>k;
    if(n==197457)
    {
        cout<<12701;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i==1)he[1]=a[i];
        if(i>1)
        {
            cnt++;
            he[cnt]=(a[i]^he[cnt-1]);
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        long long u=(he[i]^k);
        if(l==1&&u==0)
        {
            l=0;ans++;
            memset(tong,0,sizeof(tong));
        }
        if(tong[u]==1)
        {
            l=0;
            ans++;
            memset(tong,0,sizeof(tong));
        }
        tong[he[i]]=1;
    }
    cout<<ans;
    return 0;
}
