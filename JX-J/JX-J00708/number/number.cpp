#include<bits/stdc++.h>
using namespace std;
long long c[200];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string b;
    cin>>b;
    for(int i=0;i<=b.size();i++)
    {
        if('0'<=b[i]&&'9'>=b[i])
            c[b[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
        {for(int o=c[i];o>0;o--)
        cout<<i;
        }
}
