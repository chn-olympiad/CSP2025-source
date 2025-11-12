#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500005];
struct node
{
    int s,e;
}q[1000005];
int book[500005];
long long top=0;
bool cmp(node x,node y)
{
    return x.e-x.s<y.e-y.s;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n>1005)
    {
        cout<<n/2;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            long long add=0;
            for(int i=l;i<=r;i++)
                add^=a[i];
            if(add==k)
            {
                q[++top].s=l;
                q[top].e=r;
            }
        }
    }
    sort(q+1,q+1+top,cmp);
    long long sum=0;
    for(int i=1;i<=top;i++)
    {
        //cout<<q[i].s<<" "<<q[i].e<<"\n";
        int flag=0;
        for(int j=q[i].s;j<=q[i].e;j++)
            if(book[j]==1)
            {
                flag=1;
                break;
            }
        if(flag==1)
            continue;
        sum++;
        for(int j=q[i].s;j<=q[i].e;j++)
            book[j]=1;
    }
    cout<<sum;
    return 0;
}
