#include<bits/stdc++.h>
using namespace std;
char s[1100000];
int a[1100000];
int main()
{
    //#Shang4Shan3Ruo6Shui4
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int num=0;
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            a[++num]=s[i]-'0';
        }
    }
    sort(a+1,a+num+1);
    for(int i=num;i>=1;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
