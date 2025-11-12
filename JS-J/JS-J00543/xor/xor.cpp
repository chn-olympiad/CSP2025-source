#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
struct nod{
    int l,r;
};
int a[N];
int f[N];
vector<nod> ve;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    f[0] = 0;
    for(int i = 1;i<=n;i++)
    {
        int xx = f[i-1]^a[i];
        f[i] = xx;
    }
 //   printf("\n");
    for(int i = 0;i<=n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            int aa = f[i]^k;
            int bb = f[j];
            if(aa==bb)
            {
                ve.push_back({i+1,j});
            }
        }
    }
  /*  for(int i = 0;i<ve.size();i++)
    {
        printf("%d %d\n",ve[i].l,ve[i].r);
    }*/
    int maxn = 0;
    for(int i = 0;i<ve.size();i++)
    {
        int ans=1;
        for(int j = 0;j<ve.size();j++)
        {
            if(ve[i].r<ve[j].l||ve[j].r<ve[i].l)
            {
                ans++;
            }
        }
        if(ans>maxn)
        {
            maxn = ans;
        }
    }
    printf("%d",maxn);
    //printf("%d",ve.size());
    return 0;
}
