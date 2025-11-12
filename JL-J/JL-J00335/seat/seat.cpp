#include<bits/stdc++.h>
using namespace std;
const int N=115;
struct node
{
    int id,p;
    friend bool operator <(node u,node v)
    {
        return u.p>v.p;
    }
}s[N];
int n,m,x;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&x);
        s[i].id=i;
        s[i].p=x;
    }
    sort(s+1,s+n*m+1);
    int pos=1;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[pos].id==1)
                {
                    printf("%d %d",i,j);
                    return 0;
                }
                pos++;
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                if(s[pos].id==1)
                {
                    printf("%d %d",i,j);
                    return 0;
                }
                pos++;
            }
        }
    }
    return 0;
}
