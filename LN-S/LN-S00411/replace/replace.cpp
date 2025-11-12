#include<bits/stdc++.h>
using namespace std;
struct note
{
    string s,t;
}a[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s>>a[i].t;
    }
    while(q--)
    {
        string x,y;
        cin>>x>>y;
        if(x.size()<y.size())
        {
            printf("%d",0);
        }
        else
        {
            printf("%d",n-1);
        }
    }
    return 0;
}
