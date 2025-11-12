#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
string s;
int num[100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        char c=s[i];
        if(c>='0' && c<='9')
        {
            int d=c-'0';
            num[d]++;
        }
    }
    bool flag=false;
    for(int i=9; i>=1; i--)
    {
        if(num[i])
        {
            for(int j=0; j<num[i]; j++)
                printf("%d",i);
            flag=true;
        }
    }
    if(flag)
    {
        for(int i=0; i<num[0]; i++)
        {
            printf("0");
        }
    }
    else
        printf("0");

    return 0;
}
