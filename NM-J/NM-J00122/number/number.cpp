#include<bits/stdc++.h>
using namespace std;
string s;
int dis[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto i:s)
        if(i>='0'&&i<='9')
            dis[i-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=dis[i];j++)
            cout<<i;
    return 0;
}
