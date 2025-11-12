#include<bits/stdc++.h>
using namespace std;
char num[1000005];
int sum[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",num+1);
    int le=strlen(num+1);
    for(int i=1;i<=le;i++){
        if(num[i]-'0'>=0&&num[i]-'0'<=9){
            sum[num[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=sum[i];j++){
            printf("%d",i);
        }
    }
    return 0;
}
