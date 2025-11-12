#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,q;
string s1[N],s2[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int l=-1,r;
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i]){
                if(l==-1)l=i;
                r=i;
            }
        }
        string w1=t1.substr(l,r-l+1),w2=t2.substr(l,r-l+1);
        // cout<<w1<<' '<<w2<<'\n';
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s1[i].find(w1)==-1||s2[i].find(w2)==-1||t1.find(s1[i])==-1||t2.find(s2[i])==-1)continue;
            if(s1[i].find(w1)!=s2[i].find(w2)||t1.find(s1[i])!=t2.find(s2[i]))continue;
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}