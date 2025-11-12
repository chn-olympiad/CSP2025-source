#include <bits/stdc++.h>
using namespace std;
bool f=1;
string s;
int cnt[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i]!=0;i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(s[i]-'0'!=0){
                f=0;
            }
            cnt[s[i]-'0']++;
        }
    }
    if(f){
        cnt[0]=1;
    }
    for(int i=9;i>=0;i--){
        while(cnt[i]){
            cout<<i;
            cnt[i]--;
            f=1;
        }
    }
    return 0;
}
