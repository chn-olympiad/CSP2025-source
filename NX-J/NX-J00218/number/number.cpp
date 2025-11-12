#include <bit/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s;
    ll n[10]={0,0,0,0,0,0,0,0,0,0};
    while(cin>>s)
    {
        if(s-'0'>=0  && s-'0'<=9)
        {
            n[s-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(;n[i]>0;n[i]--)
            cout<<i;
    }

    return 0;
}