#include<bits/stdc++.h>
using namespace std;
long long cnt[11];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char q;
    int a;
    while(cin>>q)
    {
        if(q>='0'&&q<='9')
        {
            a=q-'0';
            cnt[a]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(cnt[i])
        {
            cout<<i;
            cnt[i]--;
        }
    }
    return 0;
}
