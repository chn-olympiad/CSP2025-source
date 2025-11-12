#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int k=1;k<=n;k++){
        cin>>s[k][1]>>s[k][2];
    }
    for(int k=1;k<=q;k++){
        string a,b;
        cin>>a>>b;
        if(a.size()!=b.size()){
            cout<<"0\n";
            continue;
        }
        int ans=0;
        for(int l=1;l<=n;l++){
            string s1=s[l][1],s2=s[l][2];
            for(int i=0;i+s1.size()-1<a.size();i++){
                if(a.substr(i,s1.size())!=s1) continue;
                string now=a.substr(0,i)+s2+a.substr(i+s1.size(),a.size()-(i+s1.size())+1);
                if(now==b){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/