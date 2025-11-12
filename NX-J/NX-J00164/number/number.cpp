#include<bits/stdc++.h>
using namespace std;

int a[1000001],cnt = 0;
char s[1000001];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s + 1);
    int l = strlen(s + 1);
    for (int i = 1;i <= l;i++)
        if (s[i] >= '0' && s[i] <= '9')
            a[++cnt] = s[i] - '0';
    sort(a + 1,a + cnt + 1);
    for (int i = cnt;i >= 1;i--)
        printf("%d",a[i]);
    return 0;
}
