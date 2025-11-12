#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int n,k,x[N];
struct node{
    int l,r;
    friend bool operator <(const node a,const node b){
        return a.r<b.r;
    }
};
vector<node> a;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    int xorn;
    for(int i=1;i<=n;i++)
    {
        xorn=0;
        for(int j=i;j<=n;j++)
        {
            xorn^=x[j];
            if(xorn==k)
            {
                a.push_back({i,j});
            }
        }
    }
    sort(a.begin(),a.end());
    int endr=0,ans=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i].l>endr)
        {
            ans++,endr=a[i].r;
        }
    }
    cout<<ans<<endl;
    return 0;
}
