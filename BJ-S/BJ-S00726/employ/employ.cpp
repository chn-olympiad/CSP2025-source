#include<iostream>
#include<cstring>
using namespace std;
int c[505],l,m,d[505],ans=0,ans1=0;
char s[505],x[505];
bool b[505];
void f(int p)
{
    if(p==l+1)
    {
        ans=0;
        for(int i=1;i<=l;i++)
        {
            if(x[i]=='1'&&d[i]<c[i])
            {
                ans++;
            }
            else if(x[i]=='0')
            {
                for(int j=i+1;j<=l;j++)
                {
                    d[j]++;
                }
            }
        }
        if(ans==m)
        {
            ans1++;
        }
        return;
    }
    for(int i=0;i<l;i++)
    {
        if(b[i]==0)
        {
            b[i]=1;
            x[p]=s[i];
            f(p+1);
            b[i]=0;
        }
    }
    return;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    l=strlen(s);
    f(1);
    cout<<ans1;
    return 0;
}
