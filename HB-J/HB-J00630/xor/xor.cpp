#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;

struct node
{
    int l,r;
    int sum;
}tree[N*4];

int n,k,cnt;
int a[N];
vector<pair<int,int>> v;

void up(int p)
{
    tree[p].sum=tree[p*2].sum^tree[p*2+1].sum;
}

void build(int p,int l,int r)
{
    tree[p].l=l;
    tree[p].r=r;

    if(l==r)
    {
        tree[p].sum=a[l];
        return;
    }

    int mid=(l+r)/2;

    build(p*2,l,mid);
    build(p*2+1,mid+1,r);

    up(p);
}

int query(int p,int l,int r)
{
    if(tree[p].l>=l&&tree[p].r<=r)
    {
        return tree[p].sum;
    }

    int mid=(tree[p].l+tree[p].r)/2;
    int a=0,b=0;

    if(l<=mid) a=query(p*2,l,r);
    if(r>mid) b=query(p*2+1,l,r);

    return a^b;
}

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second!=b.second) return a.second<b.second;
    return a.first>b.first;
}

signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(query(1,i,j)==k)
            {
                v.push_back({i,j});
            }
        }
    }

    sort(v.begin(),v.end(),cmp);

    int pre=0,len=v.size();
    for(int i=0;i<len;i++)
    {
        if(v[i].first>pre)
        {
            cnt++,pre=v[i].second;
        }
    }

    cout<<cnt<<endl;
}
