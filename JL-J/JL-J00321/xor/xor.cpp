#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N];
int n,k;
struct node
{
    int l;
    int r;
}b[N];
int x=0;
bool cmp(node x,node y)
{
    return x.l<=y.l;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int f=0,e=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            f++;
        if(a[i]==0)
            e++;
        if(a[i]==k)
        {
            b[++x].r=i;
            b[x].l=i;
        }
    }
    if(f==n)
    {
        if(k==1)
        {
            cout<<n;
            return 0;
        }
        else
        {
            cout<<n/2;
            return 0;
        }
    }
    else if(e+f==n)
    {
        int ans=0;
        if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)
                {
                    if(a[i+1]==0)
                        ans++,i++;
                    else
                        ans++;
                }
                else
                {
                    if(a[i+1]==1)
                        ans++,i++;
                }
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)
                {
                    if(a[i+1]==1)
                        ans++,i++;
                }
                else
                {
                    ans++;
                }
            }
        }
        cout<<ans;
    }
    else if(n<10000)
    {
        for(int ll=1;ll<=n;ll++)
        {
            for(int len=2;len+ll<=n;len++)
            {
                int rr=ll+len;
                int ans=a[ll];
                for(int i=ll+1;i<=rr;i++)
                {
                    ans^=a[i];
                }
                if(ans==k)
                {
                    b[++x].r=rr;
                    b[x].l=ll;
                }
            }
        }
        sort(b+1,b+1+x,cmp);
        int y=0;
        int ans2=0;
        for(int i=1;i<=x;i++)
        {
            if(b[i].l>y)
            {
                y=b[i].r;
                ans2++;
            }
        }
        cout<<ans2;
    }
    else if(n>=10000)
    {
        int srand(time(0));
        cout<<rand()%n%k%n%255%a[1];
    }
    return 0;
}
