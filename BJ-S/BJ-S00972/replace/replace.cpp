#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string s1[200005],s2[100005],t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){printf("0\n");continue;}
        int cnt=0;
        for(int i=0;i<t1.size();++i){
            if(t1[i]!=t2[i])++cnt;
        }
        ll ans=0;
        for(int i=1;i<=n;++i){
            if(s1[i].size()<cnt)continue;
            for(int l=0;l<t1.size()-s1[i].size()+1;++l){
                for(int j=l;j<=l+s1[i].size()-1;++j){
                    // cout<<i<<" "<<l<<" "<<j<<" "<<ans<<endl;
                    if(s1[i][j-l]!=t1[j]||s2[i][j-l]!=t2[j]){
                        break;
                    }else if(j==l+s1[i].size()-1)++ans;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}