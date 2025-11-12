#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int qwe(string a,string b){
    for(int i=0;i<a.size();i++){
        if(a[i]==b[0]){
            int k=i;
            for(int j=i;j<i+b.size();j++){
                if(a[j]!=b[j-k]) return 0;
            }
        }
    }
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<pair<string,string>> a[N];
    vector<pair<string,string>> b[N];
    for(int i=0;i<n;i++){
        string u,v;
        cin>>u>>v;
        a[i].push_back({u,v});
    }
    for(int i=0;i<q;i++){
        string u,v;
        cin>>u>>v;
        b[i].push_back({u,v});
    }
    for(int i=0;i<q;i++){
        int s=0;
        for(int j=0;j<n;j++){
            pair<string,string> q=a[i].push_back();
            if(qwe(a[i].first,b[i].first)==1&&qwe(a[i].second,b[i].second)) s++;
        }
    }
    cout<<s;
    return 0;
}
