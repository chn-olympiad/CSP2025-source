#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N=2e5+9;
string s[N][3];

void solved()
{
    int n,q;    cin >> n >> q ;
    for(int i=1;i<=n;i++) cin >> s[i][1] >> s[i][2] ;

    while(q--)
    {
        string t1,t2;   cin >> t1 >> t2 ;
        int ans=0;

        for(int i=1;i<=n;i++)
        {
            int len1=t1.size(),len2=s[i][1].size();
            for(int j=0;j<len1-len2+1;j++)
            {
                bool flag=true;
                for(int k=0;k<len2;k++) if(t1[j+k]!=s[i][1][k]) flag=false;

                string x=t1;
                if(flag)
                {
                    for(int k=0;k<len2;k++) x[j+k]=s[i][2][k];
                    if(x==t2) ans++;
                }
            }
        }
        cout << ans << endl ;
    }

    return ;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    int t;  cin >> t ;  while(t--)
    solved();

    return 0;
}
