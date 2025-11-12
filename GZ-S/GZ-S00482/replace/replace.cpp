//GZ-S00482 贵州师范大学云岩实验中学 陈钧雷
#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
unordered_map<int,vector<int> > pos;
int n,q,ans,pos1,pos2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        for(int i=0;i<s1.length();i++) if(s1[i]=='b'){
            pos1=i;
            break;
        }
        for(int i=0;i<s2.length();i++) if(s2[i]=='b'){
            pos2=i;
            break;
        }
        pos[pos1-pos2].push_back(s1.length());
    }
    while(q--){
        ans=0;
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            cout<<0<<'\n';
            continue;
        }
        for(int i=0;i<t1.length();i++) if(t1[i]=='b'){
            pos1=i;
            break;
        }
        for(int i=0;i<t2.length();i++) if(t2[i]=='b'){
            pos2=i;
            break;
        }
        for(int i=0;i<pos[pos1-pos2].size();i++) if(pos[pos1-pos2][i]<=t1.length()) ans++;
        cout<<ans<<'\n';
    }
    return 0;
}