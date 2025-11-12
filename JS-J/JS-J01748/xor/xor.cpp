#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
struct Node
{
    int l;
    int r;
}t[N];
int cnt[N];
bool cmp(Node x,Node y)
{
    return x.r<y.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cnt[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        cnt[i]=cnt[i-1]^a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int sum;
            if(i==j)
            {
                sum=a[i];
            }
            else
            {
               sum=(cnt[j]^cnt[i-1]);
            }
            if(sum==k)
            {
                t[++ans].l=i;
                t[ans].r=j;
            }
        }
    }
    sort(t+1,t+ans+1,cmp);
    int j=t[1].r;
    int m=1;
    for(int i=2;i<=ans;i++)
    {
        if(t[i].l>j)
        {
            m++;
            j=t[i].r;
        }
    }
    cout<<m;
    return 0;
}
