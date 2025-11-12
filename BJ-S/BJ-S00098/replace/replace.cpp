#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e6+6;
int n,q,ans;
string s1[N],s2[N];
string s,ss;
bool chk(string a,int st,string b){
    if(a.size()!=b.size())return 0;
    for(int i=st,j=0;i<a.size()&&j<b.size();j++,i++){
        if(a[i]!=b[j])return 0;
    }
    return 1;
}
string th(string a, int st,string b){
    int i=st,j=0;
    for(;st<a.size()&&j<b.size();i++,j++){
        a[i]=b[j];
    }
    if(j!=b.size()){
        for(j;j<b.size();j++){
            a+=b[j];
        }
    }
    return a;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> s1[i] >> s2[i];
    while(q--){
        cin >> s >> ss;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<s.size();j++){
                if(j+s1[i].size()>s.size())break;
                if(!chk(s,j,s1[i]))continue;
                if(chk(th(s,j,s2[i]),0,ss))ans++;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
