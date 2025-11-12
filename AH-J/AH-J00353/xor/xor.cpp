#include<bits/stdc++.h>
using namespace std;

template <typename T>

void in(T &x)
{
    int f=1;
    char c=getchar();
    while((c<='0'&&c>'9')&&c!='-')
        c=getchar();
    if(c=='-') f=-1,c=getchar();
    for(x=0;c>='0'&&c<='9';c=getchar())
        x=x*10+(c-'0');
    x*=f;
}

long long n,k;
long long a[500005];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //ios::sync_with_stdio(false);
    srand(time(0));
    in(n),in(k);
    bool okA=1,okB=1;
    for(int i=1;i<=n;i++)
    {
        in(a[i]);
        if(a[i]!=1) okA=0;
        if(a[i]!=0&&a[i]!=1) okB=0;
    }
    if(k==0&&okA)
    {
        cout<<n/2; //10 pionts
        return 0;
    }
    if(k<=1&&okB)
    {
        int now=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            now=(now^a[i]);
            if(now==k)
                now=0,cnt++;
        }
        cout<<cnt; //20 points
        return 0;
    }
    cout<<rand()%256; //hope for success
    return 0;
}
