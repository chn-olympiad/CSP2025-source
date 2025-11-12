#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000007];
int num[1000007],tot,len;
ll ans;

bool cmp(int a,int b)
{
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            num[++tot]=s[i]-'0';
    }
    sort(num+1,num+tot+1,cmp);
    for(int i=1;i<=tot;i++)
    {
        printf("%d",num[i]);
    }
    return 0;
}
