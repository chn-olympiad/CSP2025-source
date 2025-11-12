#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    string s;
    int a[100005],num=0;
    cin>>s;
    for(int i=0;i<=s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[i]=s[i]-'0';
            num++;
        }
    }
    sort(a,a+s.length(),cmp);
    for(int i=0;i<num;i++) cout<<a[i];
    return 0;
}