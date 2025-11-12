#include<bits/stdc++.h>//no end;
using namespace std;
string s[200001][3];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        int cnt=0;
        for(int i=t1.size()-1,j=t2.size()-1;i>=0&&j>=0;i--,j--)
        {
            if(t1[i]!=t2[j])break;
            cnt++;
        }
        long long ans=0;
        for(int j=1;j<=n;j++)
        {
            string ss="",sss="";
            for(int i=max(s[j][1].size()-1,t1.size()-1-cnt);i<t1.size();i++)
            {
                sss+=t2[i];
                if(ss+s[j][2]==sss)
                bool flag=1;
                for(int k=i-s[j][1].size()+1,l=0;k<=i;k++,l++)
                {
                    if(s[j][1][l]!=t1[k])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    ans++;
                }
                ss+=t1[i-s[j][1].size()+1];
            }
        }
    }
    return 0;
}
