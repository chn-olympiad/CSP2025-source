#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

int a[500010],s[500010];
struct t
{
    int l,r;
    bool operator<(t a)
    {
        if(r==a.r) return l<a.l;
        return r<a.r;
    }
};

void run()
{
    int n,k,cnt1=0,Max=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        if(a[i]==1)cnt1++;
        Max=max(Max,a[i]);
	}
    if(k==0&&Max==1)
    {
        bool flag=false;
        int ans=0,tmp=0;
        for(int i=1;i<=n;i++)
        {
            if(!flag&&!a[i])
            {
                ans++;
            }
            else if(flag&&!a[i])
            {
                tmp++;
            }
            else if(!flag&&a[i])
            {
                flag=true;
            }
            else
            {
                flag=false;
                ans+=max(1,tmp);
                tmp=0;
            }
        }
        if(flag)ans+=tmp;
        cout<<ans;
        return;
    }
    else if(k==1&&Max==1)
    {
        cout<<cnt1;
        return;
    }
    vector<t> tp;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if((s[j]^s[i-1])==k)
            {
                tp.push_back({i,j});
            }
        }
    }
    sort(tp.begin(),tp.end());
    if(tp.size()==0)
    {
        cout<<0;
        return;
    }
    int last=tp[0].r,cnt=1;
    for(int i=1;i<tp.size();i++)
    {
        if(tp[i].l>last)
        {
            last=tp[i].r;
            cnt++;
        }
    }
    cout<<cnt;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    T=1;
    while(T--)
    {
        run();
        cout<<"\n";
    }

    return 0;
}
