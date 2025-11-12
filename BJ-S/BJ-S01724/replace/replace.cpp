#include<bits/stdc++.h>
using namespace std;
//substr
//find
/*
int c[N],n=5;
int lowbit(int x){
    return x&(-x);
}
int query(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void add(int x,int val){
    while(x<=n){
        c[x]+=val;
        x+=lowbit(x);
    }
}
//luogu uid 1015780

*/
const int N=2e5+5;
string a[N],b[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,x,z,ans=0;
    string s,t,zz;
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i]>>b[i];
    //cout<<"AAAAAAAAAAAAA"<<endl;
    for(int i=1;i<=q;++i){
        ans=0;
        cin>>s>>t;
        x=s.size();
        if(x!=t.size()){
            cout<<0<<endl;
            continue;
        }
        for(int j=0;j<x;++j){
            for(int k=1;k<=n;++k){
                z=a[k].size();
                if(s.substr(j,z)==a[k]){
                    zz=s.substr(0,j)+b[k]+s.substr(j+z,x-j-z);
                    //cout<<j<<' '<<k<<' '<<zz<<endl;
                    if(zz==t) ++ans;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
