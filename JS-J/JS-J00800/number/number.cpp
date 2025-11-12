#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
char s[N];
int a[N];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    int n = strlen(s);
    int tot = 0;
    for(int i = 0;i < n;i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[++tot] = s[i] - '0';
        }
    }
    sort(a + 1,a + 1 + tot,cmp);
    for(int i = 1;i <= tot;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
