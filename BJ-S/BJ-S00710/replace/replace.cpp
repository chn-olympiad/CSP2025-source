#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<cstdio>
using namespace std;

unordered_map<string,unordered_set<string> > mp;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1].insert(s2);
    }
    for(int i=1;i<=q;i++){
        string s1,s2;
        cin>>s1>>s2;
        int l1=s1.length(),l2=s2.length();
        int pre=0,pst=l1-1;
        if(l1!=l2){
            cout<<0<<'\n';
            continue;
        }
        for(int i=0;i<l1;i++){
            if(s1[i]!=s2[i]){
                pre=i;
                break;
            }
        }
        for(int i=l1-1;i>=0;i--){
            if(s1[i]!=s2[i]){
                pst=i;
                break;
            }
        }
        int ans=0;
        for(int l=0;l<=pre;l++){
            // cout<<l<<":"<<endl;
            string now=s1.substr(l,pst-l);
            string nxt=s2.substr(l,pst-l);
            for(int r=pst;r<l1;r++){
                now+=s1[r];
                nxt+=s2[r];
                // cout<<now<<" "<<nxt<<endl;
                if(mp[now].count(nxt)){
                    // cout<<l<<" "<<r<<endl;
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}