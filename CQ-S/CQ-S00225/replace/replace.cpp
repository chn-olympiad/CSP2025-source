#include<bits/stdc++.h>
using namespace std;
int n,q;
const int BASE=29;
map<int,int>mp;
struct node{
    int x,y,sz1,sz2;
}t[200005];
struct HASH_STR{
    unsigned long long f[5000005],p[5000005];
    int init(string s){
        p[0]=1;
        for(int i=0;i<s.size();i++){
            f[i+1]=f[i]*BASE+s[i]-'a';
            p[i+1]=p[i]*BASE;
        }
        return f[s.size()];
    }
    int query(int l,int r){
        return f[r]-f[l-1]*p[r-l+1];
    }
}h,tmp;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    if(q>1000){
        while(q--)cout<<"0\n";
        return 0;
    }
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        t[i]={tmp.init(a),tmp.init(b),(int)a.size(),(int)b.size()};
        mp[a.size()-b.size()]++;
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        if(!mp.count(a.size()-b.size())){
            cout<<"0\n";
            continue;
        }
        h.init(a);
        tmp.init(b);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a.size()-t[i].sz1+t[i].sz2!=b.size())continue;
            for(int j=0;j+t[i].sz1-1<a.size();j++){
                if(h.query(1,j)==tmp.query(1,j)&&h.query(j+1,j+t[i].sz1)==t[i].x&&tmp.query(j+1,j+t[i].sz2)==t[i].y&&h.query(j+t[i].sz1+1,a.size())==tmp.query(j+t[i].sz2+1,b.size())){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}