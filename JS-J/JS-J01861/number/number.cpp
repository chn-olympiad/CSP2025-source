#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar('0'+x%10);
}
const int N=1e6+5;
char s[N];
int n,tot,cnt[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
        if(s[i]>='0'&&s[i]<='9')
            cnt[s[i]^48]++;
    for(int i=9;~i;i--)
    {
        char c='0'+i;
        while(cnt[i]--)
            putchar(c);
    }
    return 0;
}
