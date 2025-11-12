#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
struct TH
{
    string s1,s2;
}s[200005];
int yx(string a,string b,string c,string d)
{
    int sum=0;
    for(int i=0;i<a.length()-b.length();i++)
        if(a[i]==b[0])
        {
            bool pd=1;
            for(int j=1;j<b.length();j++)
                if(a[i+j]!=b[j])
                {
                    pd=0;
                    break;
                }
            if(pd==true)
            {
                for(int j=0;j<d.length();j++)
                    a[j+i]=d[j];
                if(a==c)
                    sum++;
            }
        }
    return sum;
}
bool pd2(string a,string b,string c,string d,int z)
{

    return a==c;
}
string x,y;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)
        cin >>s[i].s1>>s[i].s2;
    for(int i=1;i<=m;i++)
    {
        ans=0;
        cin >>x>>y;
        if(x.length()!=y.length())
        {
            cout <<"0"<<endl;
        }
        for(int j=1;j<=n;j++)
        {
            ans+=yx(x,s[i].s1,y,s[i].s2);
            ans+=yx(x,s[i].s2,y,s[i].s1);
        }
        cout <<ans<<endl;
    }
    return 0;
}
