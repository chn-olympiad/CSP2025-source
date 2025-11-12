#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,num;
string t1[N],t2[N],s1[N],s2[N],sa,s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>t1[i]>>t2[i];
    for(int i=1;i<=m;i++) cin>>s1[i]>>s2[i];
    for(int i=1;i<=m;i++)
    {
        s=s1[i];
        num=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<s1[i].length();k++)
            {
                int x=0;
                while(s1[i][k+x]==t1[j][x]&&x<=min(s.length(),t1[j].length())-1&&k+x<s1[i].length())
                {
                    s[k+x]=t2[j][x];
                    x++;
                }
                if(x-1==t1[j].length()-1)
                {
                    if(s==s2[i])
                    {
                        num++;
                        // cout<<s<<'\n';
                    }
                    s=s1[i];
                }
            }
        }
        cout<<num<<'\n';
    }
    
    return 0;
}