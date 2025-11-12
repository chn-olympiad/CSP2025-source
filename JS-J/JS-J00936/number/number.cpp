#include<bits/stdc++.h>
using namespace std;
string s;
char a[10000005];
int idx;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[++idx]=s[i];
        }
    }
    sort(a+1,a+idx+1,cmp);
    if(a[1]=='0'){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=idx;i++){
        cout<<a[i];
    }
    return 0;
}
