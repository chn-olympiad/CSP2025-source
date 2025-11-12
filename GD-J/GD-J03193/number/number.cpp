#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i,j,n=0,a[10];
    char c;
    memset(a,0,sizeof(a));
    while(scanf("%c",&c)&&c!='\n'){
        if(isdigit(c)){
            a[int(c-'0')]++;
            n++;
        }
    }
    for(i=9;i>=0;i--){
        for(j=0;j<a[i];j++){
            printf("%d",i);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
