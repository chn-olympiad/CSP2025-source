#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1100000];
char s[1100000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i,j=0,n;
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            j++;
            a[j]=s[i]-'0';
        }
    }
    sort(a+1,a+j+1);
    for(i=j;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
