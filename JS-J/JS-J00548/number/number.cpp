#include<bits/stdc++.h>
using namespace std;
long long ans,len=0;
string s;
char a[1000006];
bool cmp1(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[i]=s[i];
            len++;
        }
    }
    sort(a,a+len,cmp1);
    for(int i=0;i<=len;i++){
        cout<<a[i];
    }
    return 0;
}
