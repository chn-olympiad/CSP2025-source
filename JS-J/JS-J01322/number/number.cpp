#include<bits/stdc++.h>
#define rg register
#define ll long long
using namespace std;
ll k=0,ans[20];
string s;
void work(){
    cin>>s;
    for(rg ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            ans[s[i]-48]++;
    }
    for(rg ll i=9;i>=0;i--){
        while(ans[i]>0){
            ans[i]--;
            printf("%lld",i);
        }
    }
    return;
}
void fre(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    return;
}
int main(){
    fre();
    work();
    return 0;
}
