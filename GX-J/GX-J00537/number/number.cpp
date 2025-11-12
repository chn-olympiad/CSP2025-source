#include <bits/stdc++.h>
using namespace std;
char ch[1000010];
int a[1000010];
int cnt=0;
int main () {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",ch);
    int n=strlen(ch);
    for(int i=0;i<n;i++){
        if(ch[i]>='0'&&ch[i]<='9') a[cnt++]=ch[i]-'0';
    }
    sort(a,a+cnt);
    for(int j=cnt-1;j>=0;j--){
        printf("%d",a[j]);
    }
    printf("\n");
    return 0;
}