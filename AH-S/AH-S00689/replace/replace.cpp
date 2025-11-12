#include<bits/stdc++.h>
using namespace std;
int n,q;
string l[200005],r[200005];
bool check(int a,int b,string s1,string s2){
    for(int i=0;i<s1.size();i++){
        if(i>=a&&i<=b) continue;
        if(s1[i]!=s2[i]) return 0;
    }
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    while(q--){
        string a,b;
        cin>>a>>b;
        if(a.size()!=b.size()){
            cout<<0<<endl;
            continue;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            int ta=a.find(l[i]);
            int tb=b.find(r[i]);
            string w="";
            if(ta==tb&&ta!=-1){
                bool f=check(ta,ta+l[i].size()-1,a,b);
                if(f) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
