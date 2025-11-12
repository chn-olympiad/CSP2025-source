#include <bits/stdc++.h>
using namespace std;

char s[1000001];
int l=0,a[1000001];

bool camp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int x=strlen(s+1);
    for(int i=1;i<=x;i++){
        s[i]=s[i]-'0';
        if(s[i]>=0&&s[i]<=9){
            a[++l]=s[i];
        }
    }
    sort(a+1,a+1+l,camp);
    for(int i=1;i<=l;i++){
        printf("%d",a[i]);
    }
    return 0;
}
