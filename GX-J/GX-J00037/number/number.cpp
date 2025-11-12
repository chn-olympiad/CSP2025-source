#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e6+5;

char c[N];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",c+1);
    int len = strlen(c+1);
    sort(c+1,c+1+len,greater<char>());
    for(int i=1;i<=len;i++) if(c[i]>='0'&&c[i]<='9') printf("%c",c[i]);
    return 0;
}
