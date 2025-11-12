#include<bits/stdc++.h>
using namespace std;
char n[100010];
int m[100010];
int main(){
    freopen("number.in",'r',stdin);
    freopen("number.out",'w',stdout);
    scanf("%s",n);
    int len=strlen(n);
    int a=0;
    for(int i=0;i<len;i++){
        if(n[i]=='0'||n[i]=='9'||n[i]=='8'||n[i]=='7'||n[i]=='6'||n[i]=='5'||n[i]=='4'||n[i]=='3'||n[i]=='2'||n[i]=='1'){
                a++;
            m[a]=n[i]-'0';
        }
    }
    sort(m+1,m+1+a);
    for(int i=a;i>=1;i--){
        cout<<m[i];
    }
    return 0;
}
