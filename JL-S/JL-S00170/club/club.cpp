#include<bits/stdc++.h>
using namespace std;
int bb[350],a[5][350];
int b00=0,b11=0,b22=0;
void pp(int x)
{
    if(++bb[x]==3)
    {
        b22--;
        b00++;
        bb[x]=0;
        pp(x+1);
    }
    else
    {
        if(bb[x]==1)
        {
            b00--;
            b11++;
        }
        else if(bb[x]==2)
        {
            b11--;
            b22++;
        }
    }
    return;
}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n>200)
        {
            int sum=0,x,a[100005];
            for(int i=1;i<=n;i++)
            {
                cin>>a[i]>>x>>x;
            }
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++)
            {
                sum+=a[i];
            }
            cout<<sum<<'\n';
        }
        else if(n<=200)
        {
            b00=n,b11=0,b22=0;
            b00=n;
            for(int i=1;i<=n;i++)
            {
                cin>>a[0][i]>>a[1][i]>>a[2][i];
            }
            memset(bb,0,sizeof(bb));
            int maxn=0;
            for(int i=1;i<=pow(3,n);i++)
            {
                if(b00<=n/2 and b11<=n/2 and b22<=n/2)
                {
                    int sum=0;
                    for(int j=1;j<=n;j++)
                    {
                        sum+=a[bb[j]][j];
                    }
                    maxn=max(maxn,sum);
                }
                pp(1);
            }
            cout<<maxn<<'\n';
        }
    }
}
