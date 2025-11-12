#include<bits/stdc++.h>
using namespace std;
long long a[15],m=10,ma=-1;
string b;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b;
    for(long long i=0;i<b.size();i++)
    {
        if(b[i]>='0'&&b[i]<='9')
        {
            long long p=b[i]-'0';
            m=min(m,p);
            ma=max(ma,p);
            a[p]++;

        }
    }
    while(a[m]!=0)
    {
        if(a[ma]!=0)
        {
            cout<<ma;
            a[ma]--;
        }
        else
        {
            ma--;
        }
    }
    return 0;
}
