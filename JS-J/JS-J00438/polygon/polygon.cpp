#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,Mod=998244353;
int n,tree[N],a[N],m/*,b[5]*/;
/*bool vis[N];
void dfs(int n)
{
    if(n==3)
    {
        if(b[1]+b[2]>b[3])
            m+=0
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            b[n+1]=i;
            dfs(n+1);
            vis[i]=0;
        }
    }
}*/
long long gcd(long long a,long long b)
{
    if(b==0) return a;
    return (b,a%b);
}
int lowbit(int x)
{
    return -x&x;
}
int all(int to)
{
    if(to==0) return 0;
    return tree[to]+all(to-lowbit(to));
}
int sum(int l,int r)
{
    return all(r)-all(l-1);
}
void add(int w,int up)
{
    while(w<=n)
    {
        tree[w]+=up;
        w+=lowbit(w);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);//up
    if(a[n]==1)
    {
        for(int i=3;i<=n;i++)
        {
            long long s=1,w=2;
            for(int j=i;j<=n;j++)
            {
                s*=j;
                long long c=gcd(s,w);
                while(w<=n-i&&c!=1)
                {
                    s/=c;
                    w/=c;
                    if(!w)
                    {
                        w++;
                        c=gcd(s,w);
                    }
                }
            }
            s%=Mod;
            m=(m+s)%Mod;
        }
    }
    else if(n==3)
    {
        m=(a[1]+a[2]>a[3]);
    }
    else
    {
        //dfs(0);
        for(int i=1;i<=n;i++)
        {
            add(i,a[i]);
        }
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                if(sum(i,j)>a[j]*2)
                {
                    m++;
                    m%=Mod;
                }
            }
        }
    }
    cout<<m;
    return 0;
}
