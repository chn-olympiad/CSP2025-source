#include <bits/stdc++.h>
#define int long long
#define gc getchar_unlocked
using namespace std;
const int dd=1e6+5;
const int M=1e9+7;
int cnt[150];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;cin>>s;
    for(auto it:s)
        if(isdigit(it))
            cnt[it-'0']++;
    bool flag=0;
    for(int i=9;i>=1;i--){
        while(cnt[i]){
            flag=1;
            cout<<i;cnt[i]--;
        }
    }
    if(!flag)cout<<0;
    else {
        while(cnt[0]){
            cout<<0;cnt[0]--;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
