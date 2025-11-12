#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int a[N];
int main()
{
    int tot = 0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    int n = strlen(s);
    for(int i = 0;i < n;i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[tot++] = s[i] - '0';
        }
    }
    sort(a,a + tot,greater<int>());
    for(int i = 0;i < tot;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
