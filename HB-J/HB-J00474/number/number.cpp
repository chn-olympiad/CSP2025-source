#include"stdio.h"
#include"string.h"
#include<algorithm>
#define N 1000010

int num[N] = {0};
char s[N];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    int n = strlen(s),m = 0;
    for(int i=0;i<n;i++)
        if(s[i] >= '0' && s[i] <= '9')
            num[m ++] = s[i] - '0';
    std::sort(num,num + m);
    for(int i=m-1;i>=0;i--) printf("%d",num[i]);
    return 0;
}
