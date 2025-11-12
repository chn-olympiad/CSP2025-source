#include<bits/stdc++.h>
#define LL long long

using namespace std;
int read()
{
int s=0,f=1;
char c=getchar();
    while(c<'0' || c>'9')
    {
        if(c=='-') f=-1;
    c=getchar();
    }
    while(c>='0' && c<='9')
    {
    s=s*10+c-'0';
    c=getchar();
    }
return s*f;
}
void write(int x)
{
    if(x>0)
    {
    write(x/10);
    putchar(x%10+'0');
    return ;
    }
}
const int N=1e5+5;
int n,t;
struct student
{
int like[4];
    int MAX()
    {
        if(like[1]>=like[2] && like[1]>=like[3]) return 1;
        else if(like[2]>=like[1] && like[2]>=like[3]) return 2;
        else return 3;
    }
    int diff()
    {
        if(like[1]>=like[2] && like[2]>=like[3]) return like[1]-like[2];
        else if(like[1]>=like[3] && like[3]>=like[2]) return like[1]-like[3];
        else if(like[2]>=like[1] && like[1]>=like[3]) return like[2]-like[1];
        else if(like[2]>=like[3] && like[3]>=like[1]) return like[2]-like[3];
        else if(like[3]>=like[1] && like[1]>=like[2]) return like[3]-like[1];
        else if(like[3]>=like[2] && like[2]>=like[1]) return like[3]-like[2];
    }
}a[N];
int c[4][N],cnt[4],ans;
bool cmp(int x,int y)
{
    return a[x].diff()<a[y].diff();
}
void solve(int id)
{
sort(c[id]+1,c[id]+cnt[id]+1,cmp);
int s=0;
    while(cnt[id]-s>n/2)
    {
    s++;
    ans-=a[c[id][s]].diff();
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--)
    {
    n=read();
    cnt[1]=0;
    cnt[2]=0;
    cnt[3]=0;
    ans=0;
        for(int i=1;i<=n;i++)
        {
        a[i].like[1]=read();
        a[i].like[2]=read();
        a[i].like[3]=read();
        c[a[i].MAX()][++cnt[a[i].MAX()]]=i;
        ans+=a[i].like[a[i].MAX()];
        }
        if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2)
        {
        write(ans);
        printf("\n");
        continue;
        }
        if(cnt[1]>n/2) solve(1);
        else if(cnt[2]>n/2) solve(2);
        else solve(3);
        write(ans);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
