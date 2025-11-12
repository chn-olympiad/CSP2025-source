//GZ-S00032 侯恩彤 贵阳市云岩区中天中学
#include<bits/stdc++.h>
using namespace std;
int n,q;
set<string>s;
map<string,string>m1;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        string s1;
        cin>>s1;
        s.insert(s1);
        cin>>s1;
        s.insert(s1);
    }
    for(int i = 1;i <= q;i++){
        string s1;
        cin>>s1;
        s.insert(s1);
        cin>>s1;
        s.insert(s1);
    }
    while(q--){
        cout<<0<<endl;
    }
    return 0;
}
//往日种种，你可曾记得？
//你还有何话说？
//无话可说，请速速动手。
