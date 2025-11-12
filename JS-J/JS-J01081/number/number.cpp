#include<bits/stdc++.h>
using namespace std;
bool find(char c){
    return (int(c)>=int('0'))&&(int(c)<=int('9'));
}
int a[1000050],cnt=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(find(s[i])){
            cnt++;
            a[cnt]=int(s[i]-'0');
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++) cout<<a[i];
    return 0;
}
