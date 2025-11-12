#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[10];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int len=s.size();
    for(auto i:s){
        if(isdigit(i)){
            cnt[int(i-48)]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++){
            cout<<i;
        }
    }
    return 0;
}
