#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
const int MOD=998244353;
int cnt[100];
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt[s[i]-'0']++;
        }
    }
    //for(int i=0;i<=9;i++) cout<<cnt[i]<<" ";

    for(int i=9;i>=0;i--){
        //cout<<cnt[i]<<endl;
        if(cnt[i]>0){

            for(int j=1;j<=cnt[i];j++){
                cout<<i;
            }
        }

    }

}
