#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pow power
using namespace std;
template<typename T>void read(T &x)
{
    x=0;
    int fl=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=fl;
}
template<typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<typename T>void writesp(T x){write(x);putchar(' ');}
template<typename T>void writeln(T x){write(x);putchar('\n');}
const int N=1e5+5;
int n;
int a[N][3];
int sum[3];
ll ans;
priority_queue<int> q;
void solve()
{
    read(n);
    ans=0;
    sum[0]=sum[1]=sum[2]=0;
    for(int i=1;i<=n;i++) for(int j=0;j<3;j++) read(a[i][j]);
    for(int i=1;i<=n;i++)
    {
        int mx=0;
        for(int j=0;j<3;j++) mx=max(mx,a[i][j]);
        ans+=mx;
        for(int j=0;j<3;j++)
            if(a[i][j]==mx)
            {
                sum[j]++;
                break;
            }
    }
    int id=-1,cur=0;
    for(int j=0;j<3;j++)
        if(sum[j]>n/2)
        {
            id=j;
            cur=sum[j]-n/2;
            break;
        }
    // writeln(ans);writeln(id);
    if(id==-1)
    {
        writeln(ans);
        return ;
    }
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++)
    {
        int mx=0;
        for(int j=0;j<3;j++) mx=max(mx,a[i][j]);
        int did=-1;
        for(int j=0;j<3;j++)
            if(a[i][j]==mx)
            {
                did=j;
                break;
            }
        if(did!=id) continue;
        int val=0;
        for(int j=0;j<3;j++)
            if(j!=id)
                val=max(val,a[i][j]);
        val-=a[i][id];
        // cout<<val<<endl;
        q.push(val);
    }
    while(cur--)
    {
        ans+=q.top();
        q.pop();
    }
    writeln(ans);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    read(T);
    while(T--) solve();
    return 0;
}
// g++ cur.cpp -o cur -std=c++14 -O2 -static -Wall -Wextra 