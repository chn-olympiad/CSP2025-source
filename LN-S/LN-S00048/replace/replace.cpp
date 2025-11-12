#include<bits/stdc++.h>
using namespace std;
int n,q,cnt[100005];
string before[100005],now[100005],change[100005][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>change[i][0]>>change[i][1];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>before[i]>>now[i];
    }
    for(int i=1;i<=q;i++)
    {
        bool flag=1;
        for(int j=0;j<=before[i].length();j++)
        {

            for(int k=before[i].length();k>=j;k--)
            {
                if(flag)
                {
                    for(int l=1;l<=n;l++)
                    if(before[i]==change[l][0]&&now[i]==change[l][1]) cnt[i]++;
                    flag=0;
                    continue;
                }
                int tmp=j,p=0,w=0;
                string tmps="",tmpcs="",tmpx="",tmpcx="",tmpz="",tmpcz="";
                while(tmp<=k)
                {
                    tmps+=before[i][tmp];
                    tmpcs+=now[i][tmp];
                    tmp++;
                }
                while(p<j)
                {
                    tmpx+=before[i][p];
                    tmpcx+=now[i][p];
                    p++;
                }
                w=tmp+1;
                while(w<=before[i].length())
                {
                    tmpz+=before[i][p];
                    tmpcz+=now[i][p];
                    w++;
                }
                if(tmps==change[i][0]&&tmpcs==change[i][1]&&tmpx==tmpz&&tmpcx==tmpcz) cnt[i]++;
            }
        }
    }
    for(int i=1;i<=q;i++) cout<<cnt[i]<<endl;
    return 0;
}

