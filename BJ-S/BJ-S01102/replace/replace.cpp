#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
constexpr ll maxn=5e5+5,maxl=1e7+5;
ll n,q;
struct str{
    ll id,l,r;
};
vector<str> arr[maxn];
vector<ull> hsh[maxn];
unordered_map<ull,ll> mp;
ull P=13331,pw[maxl];
ll aid;
bool equ(string A,string B){
    for(int i=0;i<A.length();i++){
        if(A[i]!=B[i])return false;
    }
    return true;
}
ll getL(string A,string B){
    for(int i=0;i<A.length();i++){
        if(A[i]!=B[i]){
            return i;
        }
    }
    return A.length();
}
ll getR(string A,string B){
    for(int i=A.length()-1;i>=0;i--){
        if(A[i]!=B[i]){
            return i;
        }        
    }
    return -1;
}
void gethsh(vector<ull> &vec,string A){
    vec.clear();
    vec.push_back(A[0]);
    for(int i=1;i<A.length();i++){
        vec.push_back(vec[i-1]*P+A[i]);
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pw[0]=1;
    for(int i=1;i<maxl;i++){
        pw[i]=(pw[i-1]*P);
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;
        if(equ(x,y))continue;
        ll L=getL(x,y),R=getR(x,y);
        gethsh(hsh[i],x);
        vector<ull> yhsh;
        gethsh(yhsh,y);
        ull nwhsh=yhsh[R];
        if(L>0)nwhsh-=(yhsh[L-1]*pw[R-L+1]);
        if(mp[nwhsh]==0){
            mp[nwhsh]=++aid;
        }
        ll id=mp[nwhsh];
        arr[id].push_back({i,L,R});
    }
    while(q--){
        string x,y;
        cin>>x>>y;
        if(x.length()!=y.length()){
            cout<<0<<"\n";
            continue;
        }
        ll L=getL(x,y),R=getR(x,y);
        vector<ull> yhsh,xhsh;
        gethsh(yhsh,y);  
        gethsh(xhsh,x);
        ull nwhsh=yhsh[R];
        if(L>0)nwhsh-=(yhsh[L-1]*pw[R-L+1]);
        if(mp[nwhsh]==0){
            cout<<0<<"\n";
            continue;
        }
        ll id=mp[nwhsh];
        ll tot=0;
        for(auto v:arr[id]){
            ll l=0,r=hsh[v.id].size()-1;
            l+=L-v.l;
            r+=R-v.r;
            if(l<0 || r>=xhsh.size())continue;
            ull phsh=xhsh[r];
            if(l>0)phsh-=xhsh[l-1]*pw[r-l+1];
            //cout<<v.id<<" "<<l<<" "<<r<<" "<<phsh<<" "<<hsh[v.id][hsh[v.id].size()-1]<<"\n";
            if(phsh==hsh[v.id][hsh[v.id].size()-1])tot++;
        }                    
        cout<<tot<<"\n";
    }
    return 0;
}