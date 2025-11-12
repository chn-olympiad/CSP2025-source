#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005],x,y;
long long sum=0,n,q;
void dfs(string s)
{
    if(s==y)
    {
        sum++;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        int l=0;
        while(x[l]!=a[i][0]&&l<=n) l++;
        if(x[l]==a[i][0])
        {
            string s1=s;
            bool flag=1;
            for(int j=1;j<=a[i].size();j++)
            {
                if(s1[l+j]==a[i][j])
                {
                    s1[l+i]==b[i][j];
                }
                else break;
            }
            if(flag)
                dfs(s1);
        }
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%s %s",a+i,b+i);
    for(int i=1;i<=q;i++)
    {
        scanf("%s %s",x,y);
    }
    cout<<"0";
    return 0;
}
