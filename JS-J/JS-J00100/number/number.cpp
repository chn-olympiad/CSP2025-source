#include <bits/stdc++.h>
using namespace std;
char s[2000001];
int ls,la,a[2000001];
bool cmp(const int &A,const int &B){
    return A>B;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    ls=strlen(s+1);
    for(int i=1;i<=ls;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++la]=s[i]-'0';
        }
    }
    sort(a+1,a+la+1,cmp);
    for(int i=1;i<=la;i++){
        printf("%d",a[i]);
    }
    return 0;
}
