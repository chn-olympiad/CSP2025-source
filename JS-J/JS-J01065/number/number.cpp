#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    int tot=1;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[tot++]=s[i]-'0';
        }
    }
    sort(a+1,a+tot);
    for(int i=tot-1;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
