#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    int x=strlen(s);
    int y=0;
    for(int i=0;i<x;++i){
        if((s[i]>='0')&&(s[i]<='9')){
            a[y]=s[i]-'0';
            y++;
        }
    }
    sort(a,a+y-1,cmp);
    for(int i=0;i<y;i++){
        printf("%d",a[i]);
    }
    return 0;
}
