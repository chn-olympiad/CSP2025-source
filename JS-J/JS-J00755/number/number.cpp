#include<bits/stdc++.h>
using namespace std;
int a[10];
char s[1000002];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    for(int i=0;s[i];i++){
        if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
    }for(int i=9;i>=0;i--)for(int j=0;j<a[i];j++)printf("%d",i);
    printf("\n");
    return 0;
}