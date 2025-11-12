#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int num[1000005];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n = 0;
    for(int i = 0;i < s.size();i ++)
    {
        if(s[i] >= '0' && s[i] <='9')
        {
            num[n] = s[i] - '0';
            n ++;
        }
    }
    sort(num,num + n);
    for(int i = n - 1;i >= 0;i --)cout<<num[i];
    return 0;
}
