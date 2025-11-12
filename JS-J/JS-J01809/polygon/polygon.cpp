#include<bits/stdc++.h>
#define int long long
#define ln "\n"
using namespace std;
const int MAXN=5000;
int a[MAXN];
struct n1
{
    int z,maxn,i,maxn2,j;
} ;
n1 jie[MAXN]={0,0,0,0,0};
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        jie[i].z+=jie[i-1].z+a[i];
        jie[i].maxn=jie[i-1].maxn;
        jie[i].maxn2=jie[i-1].maxn2;
        if(a[i]>jie[i-1].maxn)
        {
            jie[i].maxn=a[i];
            jie[i].i=i;
            jie[i].maxn2=jie[i-1].maxn;
            jie[i].j=jie[i].i;
        }
        else if(a[i]>jie[i-1].maxn2)
        {
            jie[i].maxn2=a[i];
            jie[i].j=i;
        }
    }
    int ans=0;
    for(int i=n;i>=3;i--)
    {
        for(int j=i-3;j>=0;j--)
        {
            int z=jie[i].z-jie[j].z;
            int maxn;
            if(jie[i].i>j)
            {
                maxn=jie[i].maxn;
            }
            else if(jie[i].j>j)
            {
                maxn=jie[i].maxn;
            }
            else
            {
                maxn=jie[i].maxn-1;
            }
            if(z>maxn*2)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
