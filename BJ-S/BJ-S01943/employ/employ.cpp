#include<bits/stdc++.h>
using namespace std;
#define M 998244353
int p[505];
bool pd()
{
    int q[505]={0};
    for(int i=1;i<=n;i++)
    {
        q[p[i]]=p[i];
    }
    bool a=true;
    for(int i=1;i<=n;i++)
    {
        a=a&&(q[i]!=i)
    }
    return a;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n;
    cin>>m>>n;
    long long t=1,p=0;
    string s;
    int c[505];
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    while(t!=pow(m,n))
    {
        t++;
        int j=0,mm=0;
        int te=t;
        for(int i=1;i<=n;i++)
        {
            p[i]=te%m+1;
            te/=m;
        }
        if(!pd()) continue;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0'||c[i]<j)
            {
                j++;
                continue;
            }
            mm++;
        }
        if(mm>=m) p++;
    }
    return p%M;
}