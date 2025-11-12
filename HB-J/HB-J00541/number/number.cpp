#include<bits/stdc++.h>
using namespace std;

char c;
int num[12];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>c)
    {
        if('0'<=c&&c<='9')
        {
            num[c-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=num[i];j++)
        {
            cout<<i;
        }
    }
}
