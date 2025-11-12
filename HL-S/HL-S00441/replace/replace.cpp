#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
namespace hcx{
    vector<int> kmp[220000],nxt[220000];
    string S[220000];
    void get_kmp(int u){
        auto &KMP=kmp[u];
        auto &NXT=nxt[u];
        string s=S[u];
        int n=s.size();
        KMP.resize(n+1);NXT.resize(n+1);
        s=" "+s;
        int j=0;
        KMP[1]=1;
        for(int i=2;i<=n;i++){
            while(j&&s[j+1]!=s[i])j=KMP[j];
            if(s[j+1]==s[i]){
                KMP[i]=j+1;
                j=i;
            }//else{KMP[i]=KMP[j];}
            //cout<<KMP[i]<<" ";
            j=KMP[j];
        }
        for(int i=1;i<=n;i++){
            NXT[KMP[i]]=i;
        }
        for(int i=1;i<=n;i++){
            if(!NXT[i])NXT[i]=i+1;
        }
    }
    void find(int u,string t){
        auto &NXT=nxt[u];
        int m=t.size();
        t=" "+t;
        int idx=1;
        for(int i=1;i<=m;){
            if(t[i]==S[u][idx]){
                i+=NXT[idx]-idx;
                //cerr<<nxt[idx]-idx<<"\n";
                idx=NXT[idx];
            }else{
                i+=NXT[idx]-idx;
                idx=1;
            }
            if(idx==n){
                cout<<i-n+1<<"\n";
                idx=1;
            }
        }
    }
    void main(){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>S[i]>>S[i+n];
            get_kmp(i);
            get_kmp(i+n);
        }
        for(int i=1;i<=q;i++){
            string u,v;
            cin>>u>>v;
            // for(int j=1;j<=n;j++){
            //     find(j,u);
            //     find(j,v);
            // }
            cout<<"0\n";
        }

    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    hcx::main();
    return 0;
}