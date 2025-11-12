#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
int cnt[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        char x=s[i];
        if(x<'0'||x>'9') continue;
        cnt[x-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(cnt[i]){
            putchar('0'+i);
            --cnt[i];
        }
    }
}