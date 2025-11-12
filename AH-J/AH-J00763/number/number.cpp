#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int lin=s.size();
    int in=0;
    for(int i=0;i<lin;i++){
        if(s[i]>='0'&&s[i]<='9'){
            in++;
            a[in]=s[i]-'0';
        }
    }
    sort(a+1,a+in+1,cmp);
    for(int i=1;i<=in;i++){
        printf("%d",a[i]);
    }
return 0;
}
