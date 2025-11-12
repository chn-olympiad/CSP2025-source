#include<bits/stdc++.h>
using namespace std;
string s[100];
long long z[1000];
int sum,sum1,sum2,sum3;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<strlen(a);i++)
    {
        if(s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9' or s[i]=='0')
        {
            z[sum]=int(s[i]);
            sum++;
        }
    }
    while(1);
    {
        for(int i=0;i<sum;i++)
        {
            sum3=0;
            if(z[sum1]<z[sum1+1])
            {
                swap(z[sum1,z[sum1+1]);
                sum3++;
            }
            sum1++;
            if(sum1>=(sum-1))
            {
                break;
            }
        }
    }
    for(int i=0;i<strlen(z);i++)
    {
        cout<<z[i]
    }
    return 0;
}
