#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[20005][2],t1,t2;
bool cmp1(int x,int y){//s[..][1]&t1
    for(int i=0;i<s[x][1].size();i++){
        if(s[x][1][i]!=t1[i+y]) return 0;
    }
    return 1;
}
bool cmp2(int x,int y){
    for(int i=0;i<s[x][2].size();i++){
        if(s[x][2][i]!=t2[i+y]) return 0;
    }
    return 1;
}
bool cmp3(int l,int r){
    for(int i=l;i<=r;i++){
        if(t1[i]!=t2[i]) return 0;
    }
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    while(q--){
        cin>>t1>>t2;
        int ans=0;
        int m=t1.size();
        t1=" "+t1,t2=" "+t2;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i+s[i][1].size()-1>m) continue;
                if(cmp1(i,j) && cmp2(i,j) && cmp3(1,i-1) && cmp3(i+s[i][1].size(),m)){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

