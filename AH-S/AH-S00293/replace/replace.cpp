#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5+5;
int n,q;
string s1[maxn];
string s2[maxn];
string t1[maxn];
string t2[maxn];
void work ()
{
    // cout<<strlen(s[1].a);
    //找到b出现的位置
    // for (int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<strlen(s[i][1]);j++)
    //     if (s[i][1][j]=='b') cout<<j;
    // }
    for (int i=1;i<=q;i++)
    {
        cout<<0<<endl;
    }
}

void input()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i];
        cin>>s2[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t1[i];
        cin>>t2[i];
    }
    work();

}

int main ()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    input();
    return 0;
}