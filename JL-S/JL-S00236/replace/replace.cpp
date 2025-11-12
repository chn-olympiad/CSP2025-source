#include<bits/stdc++.h>
using namespace std;
string s1[100100],s2[100100],t1[100100],t2[100100];
int qa1[100100],ha1[100100],qa2[100100],ha2[100100],b[100100];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int q,n;
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++)   cin>>s1[i]>>s2[i];
    for (int i=0;i<q;i++)   cin>>t1[i]>>t2[i];
    if (n*q<=100000000)
    {
        for (int i=0;i<q;i++)
        {
            if (t1[i].size()!=t2[i].size())
            {
                puts("0");
                continue;
            }
            string sp1,sp2;
            int ans=0;
            bool flag=0;
            int ti,tj;
            for (int j=0;j<t1[i].size();j++)
            {
                if (!flag && t1[i][j]!=t2[i][j])
                {

                    flag=1;
                    ti=j;
                }
                if (t1[i][j]!=t2[i][j]) tj=j;
            }
            for (int j=ti;j<=tj;j++)
            {
                sp1+=t1[i][j];
                sp2+=t2[i][j];
            }
            for (int j=0;j<n;j++)
            {
                int t=s1[j].find(sp1),t1=s2[j].find(sp2);
                if (t==-1 || t1==-1)    continue;
                if (t!=t1)  continue;
                ans++;
            }
            printf("%d\n",ans);
        }
    }
    else
        for (int i=0;i<q;i++)   puts("0");
}
