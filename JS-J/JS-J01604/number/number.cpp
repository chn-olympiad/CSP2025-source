#include <bits/stdc++.h>
using namespace std;

long long a[1000000],b=0,c=0;
string in;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>in;
    for(int i=0;i<in.size();i++)
    {
        if(in[i]<='9'&&in[i]>='0')
        {
            a[b]=in[i]-'0';
            b++;
        }
    }
    for(int i=9;i>0;i--)
    {
        for(int j=0;j<b;j++)
        {
            if(a[j]==i)
            {
                cout<<i;
                a[j]=-1;
            }
        }
    }
}
