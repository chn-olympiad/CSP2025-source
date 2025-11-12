#include<bits/stdc++.h>
using namespace std;
string x;
int cnt[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>x;
    for(auto c:x)
        if(c>='0'&&c<='9')cnt[c-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=cnt[i];j++)cout<<i;
    return 0;
}
