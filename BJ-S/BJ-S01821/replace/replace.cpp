#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long uint64;
const int base=131;
uint64 a[5000005],b[5000005],p[5000005];
int n,q;
map<pair<uint64,uint64>,int>mp;
string s1,s2;
struct node{
    int l,r;
    uint64 h1,h2;
};
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        uint64 h1=0,h2=0;
        for(int i=0;i<s1.size();i++) h1=h1*base+s1[i],h2=h2*base+s2[i];
        mp[make_pair(h1,h2)]++;
    }
    p[0]=1;
    for(int i=1;i<=5000000;i++) p[i]=p[i-1]*base;
    while(q--){
        cin>>s1>>s2;
        s1="&"+s1,s2="&"+s2;
        int l=0x3f3f3f3f,r=0;
        for(int i=1;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                l=min(l,i);
                r=max(r,i);
            }
            a[i]=a[i-1]*base+s1[i];
            b[i]=b[i-1]*base+s2[i];
        }
        queue<node>q;
        int ans=0;
        for(int i=1;i<=l;i++){
            uint64 h1=a[r]-a[i-1]*p[r-i+1],h2=b[r]-b[i-1]*p[r-i+1];
            ans+=mp[make_pair(h1,h2)];
            for(int j=r+1;j<s1.size();j++){
                h1=h1*base+s1[i],h2=h2*base+s2[i];
                ans+=mp[make_pair(h1,h2)];
            }
        }
        cout<<ans<<endl;
    }
}
