#include<bits/stdc++.h>
using namespace std;
char s[1000010],ans[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=0;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[++cnt]=s[i];
        }
    }
    sort(ans+1,ans+cnt+1);
    for(int i=cnt;i>=1;i--){
        printf("%c",ans[i]);
    }
    return 0;
}
