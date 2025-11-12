#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int solve(string from,string to){
    string xx=from;
    int ans=0;
    for(int i=1;i<=n;i++){
        from=xx;
        if(s[i][1].size()!=s[i][2].size())continue;
        int x=from.find(s[i][1]);
        if(x!=string::npos){
            for(int j=x;j<=x+s[i][1].size()-1;j++){
                from[j]=s[i][2][j-x];
            }
        }
        if(from==to)ans++;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
    while(q--){
        string from,to;
        cin>>from>>to;
        cout<<solve(from,to)<<endl;
    }
    return 0;
}
