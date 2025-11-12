#include<bits/stdc++.h>
using namespace std;
string s;
int sum[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    s.reserve(1e6+10);
    cin>>s;

    for(int i=0;i<s.size();i++){
        int now=s[i];
        if(now>=48&&now<=57){
            ++sum[now-48];
        }
    }
    for(int i=9;i>=0;i--){
        while(sum[i]){
            cout<<i;
            --sum[i];
        }

    }
    return 0;
}
