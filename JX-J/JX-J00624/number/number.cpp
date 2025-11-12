#include<bits/stdc++.h>
using namespace std;
int cnt[10];
char a[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",&a);
    for(int i=0;i<strlen(a);i++){
        if(a[i]>='0'&&a[i]<='9'){
            if(a[i]=='9')printf("9");
            else cnt[a[i]-'0']++;
        }
    }
    for(int i=8;i>=0;i--){
        for(int j=1;j<=cnt[i];j++)printf("%d",i);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
