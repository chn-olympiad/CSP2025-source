#include<bits/stdc++.h>
using namespace std;
string inputstr,outputstr;
long long a[19],zimusum;
int main()
{
    freopen("number4.in","r",stdin);
    freopen("number4.out","w",stdout);
    cin>>inputstr;
    for(long long i=0; i<inputstr.size(); i++)
    {
        long long number=inputstr[i]-'0';
        if(number>-1&&number<10)a[number]++;
        else zimusum++;
    }
    for(long long i=9; i>-1; i--)
    {
        for(long long j=0; j<a[i]; j++)
        {
            cout<<i;
        }
    }
    return 0;
}
