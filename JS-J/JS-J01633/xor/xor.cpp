#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool u[1000005];
struct stu
{
    int l,r;
};
vector<stu>b;
int work(int la,int lb)
{
    int s=0,zh=1;
    if(la<lb) swap(la,lb);
    if(la==lb) return la;
    while(la)
    {
        s=s+(la%2!=lb%2)*zh;
        la/=2;
        lb/=2;
        zh*=2;
    }
    return s;
}
bool cmp(stu x,stu y)
{
    return x.r-x.l<y.r-y.l||(x.r-x.l==y.r-y.l&&x.l<y.l)||(x.r-x.l==y.r-y.l&&x.l==y.l&&x.r<y.r);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    int aaa=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        aaa=max(aaa,a[i]);
    }
    if(aaa==1)
    {
        if(k>1)
        {
            cout<<0;
            return 0;
        }
        else
        {
            int s1=0,s0=0;
            for(int i=1; i<=n; i++)
            {
                if(a[i]==1) s1++;
                else s0++;
            }
            if(k==1) cout<<s1;
            else
            {
                int lx=0,s=0;
                for(int i=1; i<=n; i++)
                {
                    if(a[i]==1) lx++;
                    else
                    {
                        s+=lx/2;
                        lx=0;
                    }
                }
                cout<<s0+s;
            }
            return 0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        int s=0;
        for(int j=i; j<=n; j++)
        {
            if(i==j) s=a[j];
            else s=work(s,a[j]);
            if(s==k) b.push_back({i,j});
        }
    }
    sort(b.begin(),b.end(),cmp);
    for(int i=0; i!=b.size(); i++)
    {
        bool f=1;
        for(int j=0; j<i; j++)
        {
            if(u[j]==0) continue;
            if((b[j].l<=b[i].l&&b[j].r>b[i].l)||(b[j].l>=b[i].l&&b[j].l<=b[i].r))
            {
                f=0;
                break;
            }
        }
        if(f) u[i]=1,ans++;
    }
    cout<<ans;
    return 0;
}
