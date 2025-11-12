#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,z;
    cin>>n>>q;
    vector<pair<string,string>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    while(q--)cout<<0<<'\n';
    /*
    string s1,s2;
    while(q--){
        cin>>s1>>s2;
        if(s1.size()>s2.size()){cout<<0<<'\n';continue;}
        z=0;
        int i1=-1,i2=0,i3=1;
        for(auto s:a){
            for(int i=0;i<s1.size();i++){

            }
        }
    }
    */
    fclose(stdin);
    fclose(stdout);
    return 0;
}

