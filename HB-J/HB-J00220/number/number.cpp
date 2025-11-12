#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int cnt[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(cnt[i]--)printf("%d",i);
    }
    return 0;
}
