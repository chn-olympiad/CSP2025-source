#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],q[500005],nxt[500005],l=0,ans,fst[1100000],idx[1100000],id;
int main()
{
    //long long file memory
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    q[0]=0;
    nxt[0]=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        q[i]=q[i-1]^a[i];
        if(fst[q[i]]==0)
        {
            fst[q[i]]=i;
            idx[q[i]]=i;
        }
        else
        {
            nxt[idx[q[i]]]=i;
            idx[q[i]]=i;
            nxt[i]=-1;
        }
    }
    for(int i=0;i<=(1<<20);i++)
    {
        idx[i]=fst[i];
    }
    ans=0;
    for(int r=1;r<=n;r++)
    {
        id=k^q[r];
        for(;idx[id]!=-1&&idx[id]<r;idx[id]=nxt[idx[id]])
        {
            if(idx[id]>=l&&idx[id]<r)
            {
                //cerr<<idx[id]<<r<<endl;
                ans++;
                l=r;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
