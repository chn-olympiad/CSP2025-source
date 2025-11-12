#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[1000000],a[1000000];
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",&s);
    for(int i=0,j=0;i<strlen(s);i++){
        if(s[i]>='0' && s[i]<='9')
            a[j++]=s[i];
    }
    sort(a,a+strlen(a),cmp);
    printf("%s",a);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
