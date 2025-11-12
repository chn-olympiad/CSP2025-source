#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
struct S{
    int l,r,k;
};
vector<S> s;
bool check(int l,int r)
{
    return k==a[l-1]^a[r];
}
bool cmp1(S a,S b)
{
    if(a.l==b.l)
    {
        return a.r<b.r;
    }
    return a.l<b.l;
}
bool cmp2(S a,S b)
{
    return a.r<b.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]^=a[i-1];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(check(i,j))
            {
                S temp;
                temp.l=i;
                temp.r=j;
                s.push_back(temp);
            }
        }
    }
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(s[i].l>s[j].l)
            {
                S temp=s[j];
                s[j]=s[i];
                s[i]=temp;
            }
        }
    }
    for(int i=0;i<len;i++)
    {
        int sum=0;
        for(int j=i+1;j<len;j++)
        {
            if(s[j].l>s[i].r)
                break;
            sum++;
        }
        for(int j=i-1;j>=0;j--)
        {
            if(j!=0&&s[j].r<s[j-1].r)
            {
                S temp=s[j];
                s[j]=s[j-1];
                s[j-1]=temp;
            }
            if(s[j].r<s[i].l)
                break;
            sum++;
        }
        s[i].k=sum;
    }
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(s[i].l>s[j].l)
            {
                S temp=s[j];
                s[j]=s[i];
                s[i]=temp;
            }
        }
    }
    int ans=len;
    for(int i=0;i<len;i++)
    {
        if(s[i].r>=s[i+1].l)
        {
            ans--;
            if(s[i].k>s[i+1].k)
            {
                s[i].l=2e30;
                s[i].r=-2e30;
            }
            else
            {
                s[i+1].l=2e30;
                s[i+1].r=-2e30;
            }
        }
    }
    cout<<ans;
    return 0;
}
