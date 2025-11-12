#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int ji[11];
int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    scanf("%s" , s+1);
    int len = strlen(s+1);
    for(int i = 1;i<=len;i++){
        if(s[i]>='0'&&s[i]<='9')
            ji[s[i]-'0']++;
    }
    bool you = false;
    for(int i = 9;i>=0;i--){
        if(i==0&&!you){
            printf("0");
            you = true;
        }else if(ji[i]!=0){
            you = true;
            for(int j = 1;j<=ji[i];j++)
                printf("%d" , i);
        }
    }
    if(!you)
        printf("0");
}
