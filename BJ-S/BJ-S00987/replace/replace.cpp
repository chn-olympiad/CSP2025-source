#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[100005][2],x,y;
bool match(string p,int i,int j,int k){
    for(int l=i;l<=j;l++){
        if(p[l]!=s[k][0][l-i])return false;
        else p[l]=s[k][1][l-i];
    }
    for(int l=0;l<p.size();l++){
        if(p[l]!=y[l])return false;
    }
    return true;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int p=0;p<q;p++){
        int ans=0;
        cin>>x>>y;
        for(int i=0;i<x.size();i++){
            for(int j=i+1;j<x.size();j++){
                for(int k=0;k<n;k++){
                    if(j-i+1!=s[k][0].size())continue;
                    if(match(x,i,j,k))ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}