#include<bits/stdc++.h>
#define N 1000006
using namespace std;
int n;
char s[N];
int cnt[100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if('0'<=s[i]&&s[i]<='9'){
            cnt[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(cnt[i]--){
            printf("%d",i);
        }
    }
    printf("\n");
}