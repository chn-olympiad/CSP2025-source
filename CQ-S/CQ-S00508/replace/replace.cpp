#include<bits/stdc++.h>
using namespace std;
int n,q;
#define N 200005
string s[N],t[N];
int ans;

void dfs(string str){
    // cout<<str<<endl;
    if(str==t[0]){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        int x=str.find(s[i]);
        if(str.find(s[i])!=string::npos){
            string st=str;
            st.replace(x,x+s[i].size(),t[i]);
            dfs(st);
        }
    }
    return;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    while(q--){
        cin>>s[0]>>t[0];
        ans=0;
        dfs(s[0]);
        cout<<ans<<'\n';
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/