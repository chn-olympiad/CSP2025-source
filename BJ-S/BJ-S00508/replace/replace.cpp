#include<bits/stdc++.h>
using namespace std;

string s[1000005] = {},s1[1000005] = {};

int solve(string s,string s1){
    if(s.find(s1) == 18446744073709551615) return -1;
    else return s.find(s1);
}

int main(){

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n + k;i++){
        cin>>s[i]>>s1[i];
    }
    for(int i = 1;i <= k;i++){
        int ans = 0;
        for(int j = 1;j <=n;j++){
            if(solve(s[j],s1[j]) != -1){
                ans++;
                break;
            }
        }
        cout<<0<<endl;
    }

    return 0;
}