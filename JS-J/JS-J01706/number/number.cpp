#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<int(s.size());i++){
        if(isdigit(s[i])){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]){
            cout<<i;
            a[i]--;
        }
        // cout<<a[i]<<" ";
    }
    return 0;
}