#include<bits/stdc++.h>
using namespace std;
char ch;
int a[100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(a,0,sizeof(a));
    while((ch=getchar())!='\n'){
        if(ch>='0'&&ch<='9') a[ch-48]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            printf("%d",i);
        }
    }
    return 0;
}
