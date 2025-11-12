#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char ch[N];
int len,cnt[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",ch);
    len=strlen(ch);
    for(int i=0;i<len;i++)
    {
        if(ch[i]>='0'&&ch[i]<='9') cnt[ch[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        while(cnt[i]--) printf("%d",i);
    }
    return 0;
}
