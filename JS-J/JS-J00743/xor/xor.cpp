#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],k,sum[1000005],num;
bool cmp(pair<int,int> x,pair<int,int> y)
{
    return x.second<y.second;
}
vector<pair<int,int> >v;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (i==1)
        {
            sum[i]=a[i];
        }
        else
        {
            sum[i]=sum[i-1]^a[i];
        }
    }
    for (int l=1;l<=n;l++)
    {
        for (int r=l;r<=n;r++)
        {
            int now=0;
            if (l==1)
            {
                now=sum[r];
            }
            else
            {
                now=sum[r]^sum[l-1];
            }
            if (now==k)
            {
                v.push_back({l,r});
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    int pos=0;
    for (auto i:v)
    {
        if (i.first>pos)
        {
            pos=i.second;
            num++;
        }
    }
    cout << num;
    return 0;
}
