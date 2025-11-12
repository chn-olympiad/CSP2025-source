#include<bits/stdc++.h>
using namespace std;
vector<pair<string,string>> v;
int n,q;
int f(string a,string b){
    if(a.size()!=b.size())return 0;
    int ans=0;
    for(int i=0;i<n;i++){
        string x=v[i].first,y=v[i].second;
        string aa=a;
        for(int j=0;j<=aa.size()-x.size();j++){
            string ii=aa.substr(j,j+x.size()-1);
            if(ii==x){
                ii=y;
            }
            for(int k=j;k<=j+ii.size();k++){
                aa[k]=ii[k-j];
            }
            if(aa==b) ans++;
        }
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        int ans=f(a,b);
        cout<<ans<<endl;
    }
    return 0;
}
