#include<bits/stdc++.h>
using namespace std;
int a[1000000],book[1000000];
struct ss
{
    int a,b,c;
}b[1000000];
bool cmp(ss x,ss y)
{
    return x.c>y.c;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int x,n,idx=0,ans=0;
    cin>>x>>n;
    for(int i=0;i<x;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<x;i++)
    {
        for(int j=i;j<x;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum^=a[k];
            }
            if(sum==n)
            {
                b[idx].a=i;
                b[idx].b=j;
                b[idx++].c=i-j+1;
            }
        }
    }
    sort(b,b+idx,cmp);
    for(int i=0;i<idx;i++)
    {
        int f=0;
        for(int j=b[i].a;j<=b[i].b;j++)
        {
            if(book[j]==1)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            ans++;
            for(int j=b[i].a;j<=b[i].b;j++)
            {
                book[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
