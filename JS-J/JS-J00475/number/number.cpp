#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,f[10];
char s[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if('0'<=s[i]&&s[i]<='9')f[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        if(!f[i])continue;
        for(int j=1;j<=f[i];j++){
            printf("%d",i);
        }
    }
    return 0;
}
