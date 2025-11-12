#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,q;
string s1,s2,t1,t2,ans[200005];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1,s2;
    }

    for(int j=1;j<=q;j++)
    {

        cin>>t1,t2;

    }
    for(int l=1;l<=q;l++)
    {
        for(int i=1;i<=s1.size();i++)
        {
            for(int j=1;j<=s1.size();i++)
            {
                if(s1[i]==t1[j]&&s2[i]==t2[j])
                {

                    ans[l]+=1;
                }
            }
        }
    }
    for(int i=1;i<=200005;i++)
    {
        if(ans[i]!=0)
        {
            cout<<ans[i]<<endl;
        }
    }
    return 0;

}
