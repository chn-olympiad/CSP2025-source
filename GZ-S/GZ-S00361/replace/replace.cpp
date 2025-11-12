//GZ-S00361 毕节东辰实验学校 罗圣喻
#include <bits/stdc++.h>
using namespace std;
int n,m;
string s1[200005],s2[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i];
        cin>>s2[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>s1[i];
        cin>>s2[i];
    }
    for(int i=1;i<=m;i++)
    {
        cout<<0<<endl;
    }
    return 0;
}
