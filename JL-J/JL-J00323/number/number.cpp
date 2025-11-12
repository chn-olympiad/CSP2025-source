#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int f[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            f[s[i]-'0']++;
        }
    }
    bool ok=false;
    for(int i=9;i>=0;i--){
        if(i==0&&!ok){
            printf("0");
            break;
        }
        for(int j=1;j<=f[i];j++){
            printf("%d",i);
            if(i>=1){
                ok=true;
            }
        }
    }
}
