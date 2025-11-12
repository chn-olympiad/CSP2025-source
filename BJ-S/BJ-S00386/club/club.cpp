#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n,siz[10],ans;
multiset<int>s1,s2,s3;
void solve(){
    cin>>n;
    s1.clear();
    s2.clear();
    s3.clear();
    siz[1]=0;
    siz[2]=0;
    siz[3]=0;
    ans=0;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>=max(b,c)){
            siz[1]++;
            s1.insert(min(a-b,a-c));
            ans+=a;
        }else if(b>=max(a,c)) {
            siz[2]++;
            ans+=b;
            s2.insert(min(b-a,b-c));
        }else{
            siz[3]++;
            ans+=c;
            s3.insert(min(c-a,c-b));
        }
    }
    if(siz[1]>n/2){
        for(int i=1;i<=siz[1]-n/2;i++){
            ans-=(*s1.begin());
            s1.erase(s1.begin());
        }
    }else if(siz[2]>n/2){
        for(int i=1;i<=siz[2]-n/2;i++){
            ans-=(*s2.begin());
            s2.erase(s2.begin());
        }
    }else if(siz[3]>n/2){
        for(int i=1;i<=siz[3]-n/2;i++){
            ans-=(*s3.begin());
            s3.erase(s3.begin());
        }
    }else{
        cout<<ans<<'\n';
        return;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        solve();
    }
}
