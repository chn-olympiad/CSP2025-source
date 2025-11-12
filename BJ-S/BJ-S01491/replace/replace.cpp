#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int MAXN=1e5+2;
const ll base=1e9+7;
struct node{
    vector<int> v;
    int s[26];
}E;
int n,q;
string s1,s2;
int cnt,num;
int rt1[MAXN],rt2[MAXN];
map<pair<ll,ll>,int> mp;
vector<node> v;
bool f[MAXN];
int main(){
    v.push_back(E);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        if(s1==s2) continue;
        int l=0,r=s1.size()-1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]) l++;
            else break;
        }
        for(int i=s1.size()-1;i>=0;i--){
            if(s1[i]==s2[i]) r--;
            else break;
        }
        ll c1=0,c2=0;
        for(int i=l;i<=r;i++){
            c1=c1*base+s1[i];
            c2=c2*base+s2[i];
        }
        if(!mp.count({c1,c2})){
            mp[{c1,c2}]=++cnt;
            rt1[cnt]=++num;
            rt2[cnt]=++num;
            v.push_back(E);
            v.push_back(E);
        }
        int id=mp[{c1,c2}];
        int now=rt1[id];
        for(int i=l-1;i>=0;i--){
            if(!v[now].s[s1[i]-'a']){
                v[now].s[s1[i]-'a']=++num;
                v.push_back(E);
            }
            now=v[now].s[s1[i]-'a'];
        }
        v[now].v.push_back(i);
        now=rt2[id];
        for(int i=r+1;i<s1.size();i++){
            if(!v[now].s[s1[i]-'a']) v[now].s[s1[i]-'a']=++num,v.push_back(E);
            now=v[now].s[s1[i]-'a'];
        }
        v[now].v.push_back(i);
    }
    while(q--){
        int cnt=0;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<0<<'\n';
            continue;
        }
        int l=0,r=s1.size()-1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]) l++;
            else break;
        }
        for(int i=s1.size()-1;i>=0;i--){
            if(s1[i]==s2[i]) r--;
            else break;
        }
        ll c1=0,c2=0;
        for(int i=l;i<=r;i++){
            c1=c1*base+s1[i];
            c2=c2*base+s2[i];
        }
        if(!mp.count({c1,c2})){
            cout<<0<<'\n';
            continue;
        }
        int id=mp[{c1,c2}];
        int now=rt1[id];
        for(int i=l-1;i>=0;i--){
            for(auto x:v[now].v){
                f[x]=1;
            }
            if(!v[now].s[s1[i]-'a']) break;
            now=v[now].s[s1[i]-'a'];
        }
        for(auto x:v[now].v){
            f[x]=1;
        }
        now=rt2[id];
        for(auto x:v[now].v){
            if(f[x]) cnt++;
        }
        for(int i=r+1;i<s1.size();i++){
            if(!v[now].s[s1[i]-'a']) break;
            now=v[now].s[s1[i]-'a'];
            for(auto x:v[now].v){
                if(f[x]) cnt++;
            }
        }
        cout<<cnt<<'\n';
        now=rt1[id];
        for(int i=l-1;i>=0;i--){
            for(auto x:v[now].v){
                f[x]=0;
            }
            if(!v[now].s[s1[i]-'a']) break;
            now=v[now].s[s1[i]-'a'];
        }
        for(auto x:v[now].v){
            f[x]=0;
        }
    }
    return 0;
}
