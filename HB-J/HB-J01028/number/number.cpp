#include<bits/stdc++.h>
using namespace std;
char x[1000005];
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",&x);
    for(int i=0;i<strlen(x);i++){
        if(x[i]>='0'&&x[i]<='9')a[x[i]-48]+=1;
    }
    for(int i=9;i>=0;i--){
        int c=a[i];
        while(c){
            printf("%d",i);
            c-=1;
        }
    }
    return 0;
}
