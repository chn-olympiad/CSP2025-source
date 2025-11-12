#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e6;
int n,q,ans;
int nxt[N];
int f1[N],f2[N];
char c[N];
char c1[N],c2[N];
vector <char> a[N],b[N];

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c);
        a[i].push_back('0');
        int len=strlen(c);
        for(int i=0;i<len;i++)
            a[i].push_back(c[i]);
        scanf("%s",c);
        b[i].push_back('0');
        for(int i=0;i<len;i++)
            b[i].push_back(c[i]);
    }
    if(true)
    {
        while(q--)
        {
            ans=0;
            scanf("%s%s",c1,c2);
            int len1=strlen(c1);
            for(int i=len1;i>=1;i--)
                c1[i]=c1[i-1],c2[i]=c2[i-1];
            for(int k=1;k<=n;k++)
            {
                int len2=b[k].size()-1;
                for(int i=1,j=0;i<=len2;i++)
                {
                    while(j>0 && a[k][j+1]!=a[k][i])
                        j=nxt[j];
                    if(a[k][j+1]==a[k][i])
                        j++;
                    nxt[i]=j;
                }
                for(int i=1,j=0;i<=len1;i++)
                {
                    while(j>0 && a[k][j+1]!=c1[i])
                        j=nxt[j];
                    if(a[k][j+1]==c1[i])
                        j++;
                    if(j==len2)
                    {
                        j=nxt[j];
                        f1[i]=1;
                    }
                }
                for(int i=1,j=0;i<=len2;i++)
                {
                    while(j>0 && b[k][j+1]!=b[k][i])
                        j=nxt[j];
                    if(b[k][j+1]==b[k][i])
                        j++;
                    nxt[i]=j;
                }
                for(int i=1,j=0;i<=len1;i++)
                {
                    while(j>0 && b[k][j+1]!=c2[i])
                        j=nxt[j];
                    if(b[k][j+1]==c2[i])
                        j++;
                    if(j==len2)
                    {
                        j=nxt[j];
                        f2[i]=1;
                    }
                }
                int l=N+1,r=0;
                for(int i=1;i<=len1;i++)
                {
                    if(c1[i]!=c2[i])
                        l=min(l,i),r=max(r,i);
                }
                for(int i=1;i<=len1;i++)
                {
                    if(i<r)
                        continue;
                    if(f1[i] && f2[i])
                    {
                        if((i-len2+1)<=l)
                        {
                            ans++;
                            break;
                        }
                    }
                }
                for(int i=1;i<=len1;i++)
                    f1[i]=f2[i]=0;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
