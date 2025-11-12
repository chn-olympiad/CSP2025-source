#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[100005];
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    ll cnt=0;
    cin>>a;
    for(char i:a){
        if('0'<=i && i<='9'){
            s[++cnt]=i;
        }
    }
    sort(s+1,s+cnt+1,cmp);
    for(int i=1;i<=cnt;++i){
        cout<<s[i];
    }
    return 0;
}
