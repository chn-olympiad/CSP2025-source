#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,lt[200005],rt[200005],nt,ans;
string s1[200005],s2[200005],t1,t2;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for (int i=1;i<=n;i++) cin >> s1[i] >> s2[i];
    while (q--)
    {
        ans=0;
        cin >> t1 >> t2,nt=t1.size(),t1='*'+t1,t2='*'+t2;
        lt[0]=rt[nt+1]=1;
        for (int i=1;i<=nt;i++)
        {
            if (t1[i]!=t2[i]) lt[i]=0;
            else lt[i]=lt[i-1];
        }
        for (int i=nt;i>0;i--)
        {
            if (t1[i]!=t2[i]) rt[i]=0;
            else rt[i]=rt[i+1];
        }
        for (int i=1;i<=nt;i++)
        {
            for (int j=i;j<=nt;j++)
            {
                if (lt[i-1]==0 || rt[j+1]==0) continue;
                for (int k=1;k<=n;k++)
                {
                    if (j-i+1!=s1[k].size()) continue;
                    bool tmp=1;
                    for (int l=i;l<=j;l++)
                    {
                        if (t1[l]!=s1[k][l-i])
                        {
                            tmp=0;
                            break;
                        }
                    }
                    if (!tmp) continue;
                    string tt=t1;
                    for (int l=i;l<=j;l++) tt[l]=s2[k][l-i];
                    if (tt==t2) ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}