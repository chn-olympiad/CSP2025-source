#include <bits/stdc++.h>

using namespace std;
struct node
{
    long long l,r;
};
vector<node>v;
long long sum[500002];
bool cmp(node x,node y)
{
    return x.l<y.l;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,a,sum1;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        sum[i]=sum[i-1]^a;
    }
    node v1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            sum1=sum[j]^sum[i];
            if(sum1==k)
            {
                v1.l=i+1;
                v1.r=j;
                v.push_back(v1);
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    long long rr=0,sum=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].l>rr)
        {
            rr=v[i].r;
            sum++;
        }
        else
        {
            if(v[i].r<rr)
            {
                rr=v[i].r;
            }
        }
    }
    cout<<sum;
    return 0;
}
