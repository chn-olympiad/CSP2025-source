#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string s[10000][2],t[10000][2];
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    int cnt=0;
    for(int i=1;i<=q;i++){
        cin>>t[i][1]>>t[i][2];
        if(t[i][1]==s[i][1]&&t[i][2]==s[i][2]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}