#include <iostream>
using namespace std;
string s;
int a[100],flag,p;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
    }
    for(int i=9;i>=1;i--)
    {
        while(a[i])
        {
            printf("%d",i);
            flag=1;
            a[i]--;
        }
    }
    p=0;
    while(a[0])
    {
        printf("0");
        a[0]--;
        if(flag==0)break;
    }
    return 0;
}