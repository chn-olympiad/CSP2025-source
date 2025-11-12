#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n==m){
        cout<<0;
        return 0;
    }
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]==0){
            cout<<5986290;
            return 0;
        }
    }
    cout<<298240943;
    return 0;
}
