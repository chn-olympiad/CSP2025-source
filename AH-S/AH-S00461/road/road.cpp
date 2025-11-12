#include <bits/stdc++.h>
#define int long long

using namespace std;

struct node
{
    int u,v;
    int z;
    bool operator <(const node &a)
    {
        return z <a.z;
    }
    bool operator >(const node &a)
    {
        return z >a.z;
    }
};

node make(int u,int v,int z)
{
    node t;
    t.u = u;
    t.v = v;
    t.z = z;
    return t;
}
int n,m,k;
vector<node> v;
int c[14];
int b[11111];

void case1()
{
    sort(v.begin(),v.end());
    for(int i = 1;i <= n;i++) b[i] = i;

}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);


    cin >> n >> m >>k;
    int sum = 0;
    int x,y,z;
    for(int i = 1;i <= m;i++)
    {
        scanf("%lld",&x);
        scanf("%lld",&y);
        scanf("%lld",&z);
        v.push_back(make(x,y,z));
        if(i <= n) sum += z;
    }

    bool flag = true;
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        if(c[i] != 0) flag = false;
        for(int j = 1;j <= n;j++)
        {
            scanf("%lld",&z);
            v.push_back(make(n+i,j,z));
        }
    }

    if(flag)
    {
        case1();
        return 0;
    }
    cout << sum;
    return 0;
}
