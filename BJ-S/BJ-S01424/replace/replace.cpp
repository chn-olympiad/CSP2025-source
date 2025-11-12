#include <bits/stdc++.h>
using namespace std;
string dui1[200010],dui2[200010];
string q1[200010],q2[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>dui1[i]>>dui2[i];
    for(int i=1;i<=q;i++) cin>>q1[i]>>q2[i];
    for(int i=1;i<=q;i++)//第i个问题
    {
        long long ans=0;
        for(int j=1;j<=n;j++)//第j个dui
        {
            long long tmp=0,cmp=0,hhh=0;
            for(int k=0;k<q1[i].size();k++)//遍历q
            {
                if(q1[i].size()!=q2[i].size()) continue;
                if((q2[i][k]!=dui2[j][cmp]||q1[i][k]!=dui1[j][cmp])&&tmp==0)
                {
                    cmp=0;
                }
                if(q1[i][k]!=q2[i][k]&&((tmp!=0)||(q2[i][k]!=dui2[j][cmp]||q1[i][k]!=dui1[j][cmp])))
                {
                    hhh=1;
                    break;
                }
                if(q2[i][k]==dui2[j][cmp]&&q1[i][k]==dui1[j][cmp]&&tmp==0)
                {
                    cmp++;
                }
                if(cmp==dui1[j].size())
                {
                    tmp++;
                    cmp=0;
                }
            }
            if(hhh==0) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
