#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
string s;
int a[1000005],c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('a'<=s[i]&&s[i]<='z'){
            continue;
        }
        else{
            a[c]=s[i]-'0';
            c++;
        }
    }
    sort(a,a+c+1,cmp);
    for(int i=0;i<c;i++){
        cout<<a[i];
    }
    return 0;
}
