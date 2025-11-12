#include <bits/stdc++.h>
using namespace std;
int cnt[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char ch;
    while(cin>>ch)
    {
        if(isdigit(ch))
        {
            cnt[ch-48]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(cnt[i]--)cout<<i;
    }
    return 0;
}
