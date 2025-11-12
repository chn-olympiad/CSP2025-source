#include <bits/stdc++.h>
using namespace std;
string ss;
int tt, aa[1000006];
bool cmp(int xx,int yy)
{
    return xx > yy;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> ss;
    for(int i=0;i < ss.size();i++)
    {
        if('0'<=ss[i] && ss[i]<='9')
        {
            aa[tt++]=ss[i]-'0';
        }
    }
    sort(aa,aa+tt,cmp);
    for(int i=0;i < tt;i++)
        cout << aa[i];
    return 0;
}
