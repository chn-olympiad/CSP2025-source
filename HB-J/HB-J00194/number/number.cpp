#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;cin>>a;
    vector<int>v;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9')v.push_back(a[i]-'0');
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)cout<<v[i];
    return 0;
}
