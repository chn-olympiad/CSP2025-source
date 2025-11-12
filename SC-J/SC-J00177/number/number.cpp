#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char s[maxn];

int buck[maxn];

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if('0'<=s[i]&&s[i]<='9') buck[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(buck[i]>0) putchar(i+'0'),buck[i]--;
    }
    return 0;
}