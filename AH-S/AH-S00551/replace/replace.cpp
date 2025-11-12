#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2],x,y;
map<pair<string,string>,bool> mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        mp[{s[i][0],s[i][1]}]=1;
    }
    while(q--){
        cin>>x>>y;
        int l=0,r=x.size()-1;
        while(x[l]==y[l]) l++;
        while(x[r]==y[r]) r--;
        if(l>=r){
            printf("0\n");
            continue;
        }
        int ans=0;
        for(int i=0;i<=l;i++){
            for(int j=r;j<x.size();j++){
                string p=x.substr(i,j-i+1);
                string q=y.substr(i,j-i+1);
                if(mp[{p,q}]){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
