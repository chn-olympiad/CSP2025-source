#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long l,r;
    long long j;
};

long long n,k;
long long a[500025];

vector<node> v;
bool cmp(node x,node y)
{
    return x.j<y.j;
}
long long presums[500025];
long long sums[500025];
long long sum;

long long ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

for(int i=1;i<=n;i++)
    {
        long long xoor=a[i];

        for(int j=i;j<=n;j++)
        {
            if(i!=j)
            {
                xoor=xoor^a[j];
            }
            if(xoor==k)
            {
                v.push_back((node){i,j,0});
            }
        }
    }

    for(int i=0;i<v.size();i++)
    {
        long long lll=v[i].l;
        long long rrr=v[i].r;
        presums[lll]++;
        presums[rrr+1]--;
    }
    sums[1]=presums[1];
    for(int i=2;i<=n;i++)
    {
        sums[i]=sums[i-1]+presums[i];
    }

    for(int i=0;i<v.size();i++)
    {
        long long lll=v[i].l;
        long long rrr=v[i].r;
        v[i].j=sums[i];
        long long save=sums[lll];
        for(int j=lll+1;j<=rrr;j++)
        {
            long long x=sums[j];
            if(sums[j]>save)
            {
                v[i].j+=(sums[j]-save);
            }
        }
        sum+=v[i].j;
    }

    ans=v.size();
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        if(sum==0)
        {
            break;
        }
        sum-=(2*v[i].j);
        ans--;
    }

    cout<<ans<<endl;

    return 0;
}
