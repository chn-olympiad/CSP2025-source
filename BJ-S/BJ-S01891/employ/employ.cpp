#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
const int N=25,M=998244353;
int n,m,box[N],a[N],ans=0;
bool vis[N];
string s;
int read()
{
    char ch=gc();
    int sum=0;
    while(!isdigit(ch)) ch=gc();
    while(isdigit(ch))
    {
        sum=sum*10+ch-'0';
        ch=gc();
    }
    return sum;
}
void print(int x)
{
    if(x>9) print(x/10);
    pc(x%10+'0');
    return;
}
bool chk()
{   
    int cntl=0,cntp=0;
    for(int i=1;i<=n;i++)
    {
        if(cntl>=a[box[i]]) 
        {
            cntl++;
            continue;
        }
        if(s[i-1]=='1') cntp++;
        else cntl++;
    }
    return cntp>=m;
}
void dfs(int x)
{
    if(x==n+1)
    {
        if(chk()) ans=(ans+1)%M;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        box[x]=i;
        vis[i]=1;
        dfs(x+1);
        vis[i]=0;
    }
    return;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int sum=0;
    n=read();
    m=read();
    char ch=gc();
    while(!isdigit(ch)) ch=gc();
    for(int i=1;i<=n;i++) 
    {
        s+=ch;
        ch=gc();
    }
    for(auto i:s) sum+=i-'0';
    if(sum==n)
    {
        print(n);
        return 0;
    }
    for(int i=1;i<=n;i++) a[i]=read();
    dfs(1);
    print(ans);
    return 0;
}