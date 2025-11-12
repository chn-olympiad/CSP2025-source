#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    bool ok=1;
    for(int i=1;i<=cnt;i++){
        if(ok&&!a[i]) continue;
        else{
            ok=0;
            cout<<a[i];
        }
    }
    if(ok) cout<<0;
    return 0;
}
