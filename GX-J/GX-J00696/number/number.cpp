#include<bits/stdc++.h>
using namespace std;
char s[1145140];
int t[11];
bool if_only=true;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int l=strlen(s+1);
    for(int i=1;i<=l;i++)
        if(s[i]>='0' && s[i]<='9') t[s[i]-'0']++;
    for(int i=9;i>=0;i--){
        for(int j=1;j<=t[i];j++){
            if(i) if_only=false;
            if(!i && if_only){
                printf("0");
                break;
            }
            printf("%d",i);
        }
    }
    printf("\n");
}
