#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin,s);
    for(auto a:s)
        if(isdigit(a))
            ++cnt[a-'0'];
    for(int i=9;i>=0;--i)
        for(int j=cnt[i];j;--j)
            cout<<i;
    return 0;
}