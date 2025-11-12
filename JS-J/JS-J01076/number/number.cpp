#include <bits/stdc++.h>
using namespace std;
int t[10];
char s[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    memset(t,0,sizeof(t));
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[(int)(s[i]-'0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(t[i]){
            cout<<i;
            t[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
