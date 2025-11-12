#include<bits/stdc++.h>
using namespace std;
long long a[500001],cnt;
int n,k;
pair<int,int>p[500001];
inline long long read()
{
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')if(ch=='-')f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline int read2()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')if(ch=='-')f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void write(long long x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read2(),k=read2();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            cnt++;
            p[cnt].first=i;
            p[cnt].second=i;
            continue;
        }
        long long t=a[i];
        for(int j=i-1;j>p[cnt].second;j--)
        {
            t^=a[j];
            if(t==k)
            {
                cnt++;
                p[cnt].second=i;
                p[cnt].first=j;
                break;
            }
        }
    }
    write(cnt);
    return 0;
}
