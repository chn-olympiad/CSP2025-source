#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000005],f[5000005];
struct node
{
    int l,r;
}t[5000005];
bool cmp(node x,node y)
{
    if(x.r==y.r)
    {
        return x.l>y.l;
    }
    else
    {
        return x.r<y.r;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int f1=1;
    cin>>a[1];
    f[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]^a[i];
        if(a[i]!=1)
        {
            f1=0;
        }
    }
    if(n==1)
    {
        if(n==k) cout<<1;
        else cout<<0;
        return 0;
    }
    if(n==2)
    {
        int numa=0,numb=0;
        if(a[1]==k) numa++;
        if(a[2]==k) numa++;
        if(a[1]^a[2]==k) numb++;
        cout<<max(numa,numb);
        return 0;
    }
    if(f1==1&&k==0)
    {
        cout<<n/2;
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int p=a[i];
            if(i==1)
            {
                p=f[j];
            }
            else
            {
                for(int q=i+1;q<=j;q++)
                {
                    p=p^a[q];
                }
            }
            if(p==k)
            {
                cnt++;
                t[cnt].l=i;
                t[cnt].r=j;
            }
        }
    }
    int p=0,num=0;
    sort(t+1,t+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        if(p<t[i].l)
        {
            num++;
            p=t[i].r;
        }
    }
    cout<<num;
    return 0;
}
