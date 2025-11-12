#include<bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
const ull base=131;
string s1[200005],s2[200005];
map<ull,vector<int>> mp;
ll tl[200005],tr[200005];
bool cmp(int x,int y){
    return s1[x].size()<s1[y].size();
}
inline ll gethsh(string tx){
    ull res=0;
    for (auto v:tx){
        res=res*base+v;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        // cout<<i<<"\n";
        // fflush(stdout);
        cin>>s1[i]>>s2[i];
        ll len=min(s1[i].size(),s2[i].size());
        // cout<<len<<"\n";
        ll l=-1,r=-1;
        for (int j=0;j<len;j++){
            if(s1[i][j]!=s2[i][j]){
                l=j;
                break;
            }
        }
        for (int j=len-1;j>=0;j--){
            if(s1[i][j]!=s2[i][j]){
                r=j;
                break;
            }
        }
        if(l==-1){
            continue;
        }
        // cout<<l<<" "<<r<<"\n";
        // fflush(stdout);
        string st1="",st2="";
        for (int j=l;j<=r;j++){
            st1+=s1[i][j];
            st2+=s2[i][j];
        }
        // cout<<"I'mOK\n";
        // fflush(stdout);
        mp[gethsh(st1+st2)].push_back(i);
        tl[i]=l;
    }
    for (auto t:mp){
        sort(t.second.begin(),t.second.end(),cmp);
    }
    while(q--){
        string s,t;
        cin>>s>>t;
        if(s.size()!=t.size()){
            cout<<"0\n";
            continue;
        }
        ll len=s.size();
        ll l=-1,r=-1;
        for (int j=0;j<len;j++){
            if(s[j]!=t[j]){
                l=j;
                break;
            }
        }
        for (int j=len-1;j>=0;j--){
            if(s[j]!=t[j]){
                r=j;
                break;
            }
        }
        string st1="",st2="";
        for (int j=l;j<=r;j++){
            st1+=s[j];
            st2+=t[j];
        }
        ull hsh=gethsh(st1+st2);
        if(!mp.count(hsh)){
            cout<<"0\n";
            continue;
        }
        ll cnt=0;
        for (auto v:mp[hsh]){
            if(l-tl[v]+s1[v].size()>s.size()){
                break;
            }
            if(s.substr(l-tl[v],s1[v].size())==s1[v]){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
        // fflush(stdout);
    }
    return 0;
}