#include<bits/stdc++.h>
using namespace std;
int a[500005];
vector<pair<int,int> > v;
bool cmp(pair<int,int> x,pair<int,int> y)
{
    if(x.second==y.second) return x.first<y.first;
    return x.second<y.second;
}
int main()
{
    freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=(a[i-1]^x);
    }
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            if((a[r]^a[l-1])==k)
            {
                v.push_back({l,r});
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    int las=-1;
    long long num=0;
    for(pair<int,int> i:v)
    {
        if(i.first>las)
        {
            num++;
            las=i.second;
        }
    }
    cout<<num;
    return 0;
}

