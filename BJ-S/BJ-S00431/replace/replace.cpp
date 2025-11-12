#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int l[MAXN],r[MAXN];
string s1[MAXN],s2[MAXN];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]!=s2[i][j]){
                l[i]=j;
                break;
            }
        }
        for(int j=s1[i].size()-1;j>=0;j--){
            if(s1[i][j]!=s2[i][j]){
                r[i]=j;
                break;
            }
        }
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int lef,rig;
        if(t1.size()!=t2.size()){
            cout<<0<<'\n';
            continue;
        }
        for(int j=0;j<t1.size();j++){
            if(t1[j]!=t2[j]){
                lef=j;
                break;
            }
        }
        for(int j=t1.size()-1;j>=0;j--){
            if(t1[j]!=t2[j]){
                rig=j;
                break;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(r[i]-l[i] != rig-lef){
                continue;
            }
            if(lef-l[i]<0 || rig-r[i]<0)  continue;
            if(t1.substr(lef-l[i],s1[i].size())==s1[i]
               && t2.substr(rig-r[i],s2[i].size())==s2[i]){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }


    return 0;
}
