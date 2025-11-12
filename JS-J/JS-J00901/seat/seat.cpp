#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int read()
{
    int x=0,f=1;
    char c;
    c=getchar();
    while((c<'0'||c>'9')&&c!='-')   c=getchar();
    if(c=='-')
    {
        f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

int n,m,a[105],s,pos;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m>>s;
    a[1]=s;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(s==a[i])
        {
            pos=i;
            break;
        }
    }
    pos=n*m+1-pos;

    int x=(pos-1)/n+1,y;
    y=pos%n;
    if(y==0)    y=n;
    if(x%2==0)    y=n+1-pos%n;
    cout<<x<<" "<<y;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
