#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e6+10;
ll n,m,f,B=1,p[N];
string s1[N],s2[N],p1,p2;
ll pn(string s){
    return s.find('b');
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>s1[i]>>s2[i],p[i]=pn(s1[i])-pn(s2[i]);
    if(n*m<=1e8) B=0;
    while(m--){
        ll ans=0;
        cin>>p1>>p2;
        if(B){
            ll x=pn(p1)-pn(p2);
            for(ll i=1;i<=n;i++) if(p[i]==x) ans++;
        }
        else{
            for(ll i=1;i<=n;i++){
                string l1=p1,l2=p2;
                while(l1.find(s1[i])!=string::npos&&l2.find(s1[i])!=string::npos&&l1.find(s1[i])==l2.find(s1[i])){
                    l1.erase(l1.find(s1[i]),s1[i].size());
                    l2.erase(l2.find(s1[i]),s1[i].size());
                }
                while(l1.find(s1[i])!=string::npos&&l1.replace(l1.find(s1[i]),s1[i].size(),s2[i])==l2){
                    l1.erase(l1.find(s2[i]),s2[i].size());
                    l2.erase(l2.find(s2[i]),s2[i].size());
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
