#include<bits/stdc++.h>
using namespace std;
int a[1001000];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int wh=0;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0&&s[i]-'0'<=9){
            wh++;
            a[wh]=s[i]-'0';
        }
    }
    sort(a+1,a+wh+1,cmp);
    for(int i=1;i<=wh;i++) cout<<a[i];
    return 0;
}
