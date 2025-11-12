#include<bits/stdc++.h>
int k=1,a[1010];
char s[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=0;i<strlen(s);i++){
        scanf("%c",&s);
        if(s[i]>='1'&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
        }
        else if(s[i]=='0'){
            a[k]==0;
            k++;
        }
    }
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
