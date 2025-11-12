#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long u64;
const int N=2e5+10,M=5e6+10;
vector<pair<string,string> > g[N];
map<int,int> mp;int tot=0;
u64 pw[M],hx[M];u64 bs=1331;
cc_hash_table<u64,int> htb[4000];
int ln[N];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) {
        string s,t;cin>>s>>t;
        if(!mp[s.length()]) {
            mp[s.length()]=++tot;
            ln[tot]=s.length();
        }int pt=mp[s.length()];
        g[pt].push_back({s,t});
        u64 tp=0;
        for(int i=0;i<s.length();i++) {
            tp=tp*bs+s[i]-'a'+1;
        }
        for(int i=0;i<t.length();i++) {
            tp=tp*bs+t[i]-'a'+1;
        }htb[pt][tp]++;
    }pw[0]=1;
    for(int i=1;i<M;i++) pw[i]=pw[i-1]*bs;
    for(int qid=1;qid<=q;qid++) {

        string t1,t2;cin>>t1>>t2;int lk=t1.length();
        if(t1.length()!=t2.length()) {cout<<0<<endl;continue;}
        int mx=0,mn=1e9;
        for(int i=0;i<lk;i++) {
            if(t1[i]!=t2[i]) mx=max(mx,i),mn=min(mn,i);
        }int ret=0;
        for(int _=1;_<=tot;_++)
        {
            int k=ln[_];// cout<<k<<' '<<lk<<endl;
            if(lk<k) continue;
            if(k<mx-mn+1) continue;
            u64 a=0,b=0;
            for(int i=0;i<k;i++) a=(a*bs)+t1[i]-'a'+1;
            for(int i=0;i<k;i++) b=(b*bs)+t2[i]-'a'+1;
            for(int i=k;i<=lk;i++) {
                // cout<<a<<' '<<b<<' '<<a*pw[k]+b<<endl;
                if(i-k<=mn && i-1>=mx) {
                // cout<<a<<' '<<b<<' '<<a*pw[k]+b<<endl;
                    ret+=htb[_][a*pw[k]+b];
                }
                if(i==lk) continue;
                a=a*bs+t1[i]-'a'+1;
                b=b*bs+t2[i]-'a'+1;
                a-=pw[k]*(t1[i-k]-'a'+1);
                b-=pw[k]*(t2[i-k]-'a'+1);
                // cout<<"  "<<a<<' '<<b<<' '<<a*pw[k]+b<<endl;

            }
        }cout<<ret<<'\n';
    }return 0;
}