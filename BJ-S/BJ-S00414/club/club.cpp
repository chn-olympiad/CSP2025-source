// nahida纳西妲
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;
struct bro{
    long long a;
    long long b;
    long long c;
} lzw[100005];
long long n;
long long bestans;
long long halfn;
void dfs(long long now,long long groupa,long long groupb,long long groupc,long long ans)
{
    if(groupa>halfn && groupb > halfn && groupc > halfn)
    {
        return;
    }
    if(now == n)
    {
        //cout << "===============" << endl;
        //cout << ans << endl;
        //for (long long i=0;i<n;i++)
        //{
        //    cout << used[i] << " ";
        //}
        //cout << endl;
        //cout << "===============" << endl;
        
        if (ans>bestans || bestans == -1)
        {
            
            if(groupa<=halfn && groupb <= halfn && groupc <= halfn)
            {
                bestans=ans;
                return;
            }
            
        }
        return;
    }
    if(groupa+1<=halfn)
    {
        dfs(now+1,groupa+1,groupb,groupc,ans+lzw[now].a);
    }
    if(groupb+1<=halfn)
    {
        dfs(now+1,groupa,groupb+1,groupc,ans+lzw[now].b);
    }
    if(groupa+1<=halfn)
    {
        dfs(now+1,groupa,groupb,groupc+1,ans+lzw[now].c);
    }
    return;
}


short used[100005];
long long solve1() // chun tan xin
{
    long long ansa=0,usea=0,useb=0,usec=0;
    for (long long i=0;i<n;i++)
    {
        long long a=lzw[i].a,b=lzw[i].b,c=lzw[i].c;
        if(a>b && a>c)
        {
            usea++;
            ansa+=a;
        }
        if(b>a && b>c)
        {
            useb++;
            ansa+=b;
        }
        if(c>a && c>b)
        {
            usec++;
            ansa+=c;
        }
        if(usea > halfn || useb > halfn || usec > halfn)
        {
            return -1;
        }
    }
    return ansa;
}

long long solve2_cmpa(bro a,bro b)
{
    return a.a > b.a;
}
long long solve2_cmpb(bro a,bro b)
{
    return a.b > b.b;
}
long long solve2_cmpc(bro a,bro b)
{
    return a.c > b.c;
}

long long maxx(long long a,long long b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
long long solve2()
{
    long long ans=0;
    long long besta=0,bestb=0,bestc=0;
    sort(lzw,lzw+n,solve2_cmpa);
    for (long long i=0;i<halfn;i++)
    {
        besta+=lzw[i].a;
    }
    sort(lzw,lzw+n,solve2_cmpb);
    for (long long i=0;i<halfn;i++)
    {
        bestb+=lzw[i].b;
    }
    sort(lzw,lzw+n,solve2_cmpc);
    for (long long i=0;i<halfn;i++)
    {
        bestc+=lzw[i].c;
    }

    if(besta>=bestb && bestb>=bestc)
    {
        sort(lzw,lzw+n,solve2_cmpa);
        ans=besta;
        for (long long i=halfn;i<n;i++)
        {
            ans+=maxx(lzw[i].b,lzw[i].c);
        }
        return ans;
    }
    if(bestb>=bestc && bestb>=besta)
    {
        sort(lzw,lzw+n,solve2_cmpb);
        ans=bestb;
        for (long long i=halfn;i<n;i++)
        {
            ans+=maxx(lzw[i].a,lzw[i].c);
        }
        return ans;
    }
    else
    {
        ans=bestc;
        for (long long i=halfn;i<n;i++)
        {
            ans+=maxx(lzw[i].a,lzw[i].b);
        }
        return ans;
    }
    
    
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    long long t;
    cin >> t;
    for (long long round=0;round<t;round++)
    {
        cin >> n;
        for (long long i=0;i<n;i++)
        {
            cin >> lzw[i].a >> lzw[i].b >> lzw[i].c;
        }
        halfn=n/2;
        bestans=solve1(); // 纯贪心
        if(bestans!=-1)
        {
            
            cout << bestans << endl;
            continue;
        }
        if(n>10)
        {
            
            bestans=solve2();
            cout << bestans << endl;
            continue;
        }
        else
        {
            dfs(0,0,0,0,0); //  暴力求解
        }
        
        cout << bestans << endl;
    }
    
    return 0;
}