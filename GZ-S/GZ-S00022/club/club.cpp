//GZ-S00022 何奕歆 凯里市第一初级中学
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        int n,m;cin>>n;
        m=n/2;
        int  s[n][3],num[3],all=0;
        for(int i=0;i<n;i++)
        {
            cin>>s[i][0]>>s[i][1]>>s[i][2];
        }
        for(int i=0;i<n;i++)
        {
            int p=max(s[i][0],max(s[i][1],s[i][2])),op=0;
            for(int j=0;j<n;j++)
            {

                if(p==s[i][j])
                {
                    if(num[j]<m)
                    {
                        num[j]++;all+=s[i][j];break;
                    }

                }
                else if (op==0)
                    {
                        p=s[i][0]+s[i][1]+s[i][2]-p-min(s[i][0],min(s[i][1],s[i][2]));op++;
                        j=0;
                    }
                    else
                    {
                        p=min(s[i][0],min(s[i][1],s[i][2]));
                        j=0;
                    }
            }
        }
        cout<<all;
    }

    return 0;
}
