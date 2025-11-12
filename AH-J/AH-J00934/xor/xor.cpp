#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k;
int a[500005];
int f[500005];
int pos[1500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=a[i]^a[i-1];
    }
    memset(pos,-1,sizeof(pos));
    pos[0]=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        if(pos[a[i]^k]!=-1)
            f[i]=max(f[i],f[pos[a[i]^k]]+1);
        pos[a[i]]=i;
        //cout<<a[i]<<" "<<f[i]<<"\n";
    }
    cout<<f[n];
    return 0;
}

