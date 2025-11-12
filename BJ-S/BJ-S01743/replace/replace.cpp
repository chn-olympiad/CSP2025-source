#include<bits/stdc++.h>
using namespace std;
map<string,string> m;
string add(int st,int en,string str)
{
    string re;
    for(int i=st;i<=en;i++)
    {
        re=re+str[i];
    }
    return re;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    for(int i=1;i<=n;i++)
    {
        string str1,str2;
        cin>>str1>>str2;
        m[str1]=str2;
    }
    while(q--)
    {
        int z=0;
        string t1,t2;
        cin>>t1>>t2;
        int st=-1,en;
        for(int i=0;i<t1.size();i++)
        {
            if(t1[i]!=t2[i])
            {
                if(st=-1)
                {
                    st=i;
                }
                en=i;
            }
        }
        for(int i=0;i<=st;i++)
        {
            for(int j=en;j<t1.size();j++)
            {
                if(m[add(i,j,t1)]==add(i,j,t2))
                {
                    z++;
                }
            }
        }
        cout<<z<<"\n";
    }
    return 0;
}
