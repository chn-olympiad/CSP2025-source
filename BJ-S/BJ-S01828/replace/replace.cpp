#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
Ren5Jie4Di4Ling5%
*/
int n,q;
const int N=2050;
map<string,map<string,int>>mp;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1][s2]++;
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int sz=t1.size();
        int ans=0;
        for(int l=1;l<=sz;l++){
            string tmp1="",tmp2="";
            for(int r=sz;r>=l;r--){
                string tmp1=t1.substr(l-1,r-l+1);
                string tmp2=t2.substr(l-1,r-l+1);
                //cout<<tmp1<<" "<<tmp2<<"\n";
                if(mp[tmp1].count(tmp2))
                ans+=mp[tmp1][tmp2];
                if(t1[r-1]!=t2[r-1])break;
            }
            if(t1[l-1]!=t2[l-1])break;
        }
        cout<<ans<<"\n";
    }
}
