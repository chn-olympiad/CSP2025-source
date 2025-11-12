#include<bits/stdc++.h>
using namespace std;
int n,a[66];
char s[1000666];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++) if (s[i]>='0'&&s[i]<='9') ++a[s[i]-'0'];
    for (int i=9;i>=0;i--) for (;a[i]--;) printf("%d",i);
    return 0;
}
