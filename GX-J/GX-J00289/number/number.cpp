#include<bits/stdc++.h>
using namespace std;
string w;
char s[0x7f];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>w;
    for(int i=0;i<w.size();i++)
    {
        if(int(w[i])>=48&&int(w[i])<=57)
        {
            s[i]=w[i];
        }
    }
    sort(s,s+w.size(),cmp);
    for(int i=0;i<w.size();i++) cout<<s[i];
    return 0;
}
