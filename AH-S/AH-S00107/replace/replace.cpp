#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,m[200005],ha1[5000005],ha2[5000005],ha3[5000005],ha4[5000005],b[5000005],b1[5000005],ans;
char s[5000005],t[5000005],ss[200005],tt[200005];
const int p=1000000009;
inline int as1(int i){return ha1[i];}
inline int as2(int i){return ha2[i];}
inline int as3(int l,int r){if(l>r)return 0;return (ha3[r]-ha3[l-1]+p)*b1[l-1]%p;}
inline int as4(int l,int r){if(l>r)return 0;return (ha4[r]-ha4[l-1]+p)*b1[l-1]%p;}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;b[1]=131;b1[1]=526717562;b[0]=b1[0]=1;
    for(int i=1;i<=5000000;i++){
        b[i]=b[i-1]*b[1]%p;
        b1[i]=b1[i-1]*b1[1]%p;
    }
    for(int i=1;i<=n;i++){
        cin>>(s+1)>>(t+1);ss[i]=s[1];tt[i]=t[1];
        m[i]=strlen(s+1);
        for(int j=1;j<=m[i];j++)ha1[i]=(ha1[i]+b[j]*(s[j]-'a'))%p;
        for(int j=1;j<=m[i];j++)ha2[i]=(ha2[i]+b[j]*(t[j]-'a'))%p;
    }
    while(q--){
        cin>>(s+1)>>(t+1);ans=0;
        int o=strlen(s+1);vector<int> w[10005];
        for(int j=1;j<=o;j++)ha3[j]=(ha3[j-1]+b[j]*(s[j]-'a'))%p,w[(s[j]-'a')*26+t[j]-'a'].push_back(j);
        for(int j=1;j<=o;j++)ha4[j]=(ha4[j-1]+b[j]*(t[j]-'a'))%p;
        for(int i=1;i<=n;i++){
            for(int j=0;j<w[(ss[i]-'a')*26+tt[i]-'a'].size();j++){
                int l=w[(ss[i]-'a')*26+tt[i]-'a'][j],r=l+m[i]-1;
                if(as3(1,l-1)==as4(1,l-1)&&as3(r+1,o)==as4(r+1,o)&&as1(i)==as3(l,r)&&as2(i)==as4(l,r))ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
