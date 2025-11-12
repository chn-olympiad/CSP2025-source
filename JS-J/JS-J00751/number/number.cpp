#include <bits/stdc++.h>
using namespace std;

bool isdigit(char n)
{
    return true;
}
string popback(string d,int u)
{
    d[u]=0;
    for (int k=u; k<=d.length();k++)
    {
        d[k]=d[k+1];
    }
    return d;
}
string declar(string o)
{
    o[o.length()]=0;
    return o;
}
string maxnumber(int m,string p)
{
    for (int j=1; j<=p.length()+1; j++)
    {
        if(m>=p[j])
            popback(p,j-1);
            p[j-1]=m;
    }
    return p;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    string ans2;
    ans2[1]=0;
    long long cnt=1;
    cin >> s;
    for(int i=1; i<=s.length(); i++)
    {
        if(isdigit(s[i])==true)
        {
            maxnumber(s[i],ans2) = ans2;
        }
    }
    declar(ans2);
    cout << ans2 << endl;
    return 0;
}
