#include<bits/stdc++.h>
using namespace std;
int s[500005];

int x(int a,int b)
{
    int sum=s[a];
    a++;
    for(int i=a;i<=b;i++)
    {
        sum=sum^s[i];
    }
    return sum;
}
struct L
{
    int begin,end,sub;
};
vector<L>a;
bool cmp(L x,L y)
{
    if(x.begin==y.begin)return x.sub<y.sub;
    return x.begin<y.begin;
}
int fia(string t,int v)
{
    for(int i=0;i<a.size();i++)
    {
        if(t=="begin")
        {
            if(a[i].begin==v)return i;
        }
        else if(t=="end")
        {
            if(a[i].end==v)return i;
        }
        else if(t=="sub")
        {
            if(a[i].sub==v)return i;
        }
    }
    return -1;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int u=x(i,j);
            if(u==k)
            {
                L e;
                e.begin=i;
                e.end=j;
                e.sub=j-i+1;
                a.push_back(e);
            }
        }
    }
    sort(a.begin(),a.end(),cmp);
    int en=0;
    int sum=0;
    while(en<n)
    {
        int g=fia("begin",en);
        if(g==-1)
        {
            en++;
            continue;
        }
        en+=a[g].sub;
        sum++;
    }
    cout<<sum;
    return 0;
}