#include <bits/stdc++.h>
using namespace std;
int n,q;
struct si
{
    string  s1,s2;
    void read()
    {
        cin>>s1>>s2;
    }
}s[200010];
int a[100010];
bool check(string a,string b)
{
    if(a.size()!=b.size()) return 0;
    for (int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout)
    cin>>n>>q;
    for (int i=1;i<=n;i++) s[i].read();
    while(q--)
    {
        string x,y;
        cin>>x>>y;
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            string x1=x,y1=y;
            if(x1.find(s[i].s1)==-1) continue;
            x1.replace(x1.find(s[i].s1),s[i].s1.size(),s[i].s2);
            if(check(x1,y1)) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}