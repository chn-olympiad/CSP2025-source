#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,ans;
string p,q,r1,r2;
struct node{
    string a,b;
    int l;
}x[200005];
bool cmp(node a,node b)
{
    return a.l>b.l;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>x[i].a>>x[i].b;
        x[i].l=x[i].a.size();
    }
    sort(x,x+n,cmp);
    for(int i=0;i<m;i++)
    {
        cin>>p>>q;
        k=p.size();
        t=ans=0;
        for(int j=0;j<n;j++)
        {
            if(p[j]!=q[j])
            {
                r1=r1+p[j];
                r2=r2+q[j];
                t++;
            }
        }
        for(int j=0;j<n;j++)
        {
            if(x[j].l>k)continue;
            if(x[j].l<t)break;
            if(x[j].a.find(r1)!= x[j].a.find("0") && x[j].b.find(r2)!= x[j].a.find("0") && p.find(x[j].a)!= x[j].a.find("0") )
            {
                if(x[j].a.find(r1)==x[j].b.find(r2))ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
