#include <bits/stdc++.h>
using namespace std;
int a[1000010],len,cnt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    len=str.length();
    for(int i=0;i<len;i=-~i){
        if(str[i]>='0'&&str[i]<='9') a[++cnt]=str[i]-48;
    }
    sort(a+1,a+1+cnt,cmp);
    if(a[1]==0){
        printf("0");
        return 0;
    }
    for(int i=1;i<=cnt;i=-~i) printf("%d",a[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
