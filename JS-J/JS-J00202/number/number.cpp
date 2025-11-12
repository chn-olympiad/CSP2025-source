#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[1000005],t[1000005];
int n=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    for (int i=1;s[i];++i){if (isdigit(s[i])){t[++n]=s[i];}}
    sort(t+1,t+1+n,greater<char>());
    puts(t+1);
    return 0;
}
