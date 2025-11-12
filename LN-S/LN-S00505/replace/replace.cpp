# include <bits/stdc++.h>
using namespace std;
const int N = 110;
string s[N],t[N];
string a[N],b[N];
int main (){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i] >> t[i];
    }   
    while(q--)
    {
        string x,y;
        cin >> x >> y;
        x = ' '+x;
        y = ' '+y;
        int len1 = x.size();
        int ans = 0;
        for(int i = 1;i <= len1;i++)
        {
            if(x[i] != y[i])
            {
                string pp = "",pp2 = "";
                int p = i;
                while(p <= n)
                {
                    if(x[p] == y[p]) break;
                    pp += x[p];
                    pp2 += y[p];
                    p++;
                }
                string cnt = "";
                string cnt2 = "";
                for(int j = 1;j < i;j++)
                {
                    cnt += x[j];
                }
                for(int j = p;j <= len1;j++)
                {
                    cnt2 += x[j];
                }
                string xx = "";
                for(int j = 1;j <= n;j++)
                {
                    if(s[j] == pp && t[j] == pp2)
                    {
                        xx = cnt+pp2+cnt2;
                        break;
                    }
                }
                x = xx;
                if(x == y)
                {
                    ans++;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}