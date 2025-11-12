#include<bits/stdc++.h>
using namespace std;
const int LEN=1e6+50;
int num[10];
char s[LEN];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<strlen(s);i++)
    {
        if(int(s[i]-'0')<=9&&int(s[i]-'0')>=0)
        {
            num[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int RP=1;RP<=num[i];RP++)
        {
            printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}
    /*
    */
