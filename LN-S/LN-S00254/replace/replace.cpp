#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
typedef pair<int,char> PII;
int n,q,ans;
string s1,s2;
string s[N][2];
bool bin[27];
int Q[N],h=1,t=0;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    while(q--)
    {
        ans=0;
        cin>>s1>>s2;
        s1=' '+s1;
        s2=' '+s2;

        for(int i=1;i<=s1.size();i++)
        {
            if(s1[i]!=s2[i]) Q[++t]=i;
        }
        if(t==0)
        {
            printf("0\n");
        }
        for(int i=1;i<=n;i++) 
        {
            cin>>s[n][0]>>s[n][1];
            for(int j=0;j<s[n][0].size();j++)
            {
                bin[s[i][0][j]-'a']=1;
            }
        }
        bool f=0;
       for(int i=1;i<=n;i++)
       {
           if(t-h+1==s[i][0].size())
           {
               for(int j=h;j<=t;j++)
               {
                   if(s1[j]!=s[i][0][j]) 
                   {
                       f=1;break;
                   }
                    if(f==0) ans++;
               }

           }
       }
       printf("%d\n",ans);

    }
    fclose(stdin);fclose(stdout);
    return 0;
}