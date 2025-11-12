#include <bits/stdc++.h>
using namespace std;
int n,q;
string S[200005][2];
string t1,t2;
string solve(int x,string s){
    bool f=1;
    for(int i=0;t1[i]!=0;i++){
        s=t1;
        if(s[i]==S[x][0][0]){
            for(int j=0;S[x][0][j]!=0;j++){
                if(S[x][0][j]!=s[i+j]||S[x][1][j]!=t2[i+j]){
                    f=0;
                    break;
                }
                s[i+j]=S[x][1][j];
            }
            if(f==1){
                return s;
            }
        }
    }
    if(f==1){
        return t1;
    }
    return "";
}
int main (){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>S[i][0]>>S[i][1];
    }
    while(q--){
        int ans=0;
        cin>>t1>>t2;
        for(int i=0;i<n;i++){
            if(solve(i,t1)==t2){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return  0;
}
