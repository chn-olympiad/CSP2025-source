#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
using big = long long;

int cnt[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;cin>>s;
    for(char c : s){
        if('0'<=c && c<='9') cnt[c-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++){
            cout<<i;
        }
    }
    return 0;
}
