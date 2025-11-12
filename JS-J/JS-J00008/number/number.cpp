#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[11];
char s[1000010];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(isdigit(s[i])){
            cnt[s[i]-'0']++;
        }
    }
    bool flag=true;
    for(int i=9;i>=0;i--){
        if(i==0&&flag){
            cout<<0;
            return 0;
        }
        if(cnt[i]>=1){
            flag=false;
            for(int j=0;j<cnt[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
