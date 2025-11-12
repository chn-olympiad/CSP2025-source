#include<bits/stdc++.h>
using namespace std;
const int BASE=131,MOD=1e9+7;
namespace FileIO{
    void Test(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen("test.out","w",stdout);
    }
    void File(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
int n,q;
string s[200005][2];
pair<int,int> dif[200005];
int dnum[200005];
vector<int> ha[200005][2];
int pw[200005];
int Get(string &s,vector<int> &ha,int l,int r){
    if(l<0||r>=s.size()){
        // printf("Get:");
        cerr<<s<<' '<<l<<' '<<r<<'\n';
    }
    return (ha[r]-1ll*pw[r-l+1]*(l==0?0:ha[l-1])%MOD+MOD)%MOD;
}
void Work(){
    cin>>n>>q;
    pw[0]=1;
    for(int i=1;i<=200000;i++){
        pw[i]=1ll*pw[i-1]*BASE%MOD;
    }
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        if(s[i][0]==s[i][1]){
            n--,i--;
            continue;
        }
        dif[i].first=-1;
        for(int j=0;j<s[i][0].size();j++){
            if(s[i][0][j]!=s[i][1][j]){
                dnum[i]++;
                if(dif[i].first==-1) dif[i].first=j;
                dif[i].second=j; 
            }
        }
        // printf("dif:[%d %d]\n",dif[i].first,dif[i].second);
        for(int j=0;j<=1;j++){
            int tmp=0;
            for(int k=0;k<s[i][j].size();k++){
                tmp=(1ll*tmp*BASE+s[i][j][k]-'a')%MOD;
                ha[i][j].push_back(tmp);
            }
        }
    }
    while(q--){
        string t[2];
        vector<int>tha[2];
        int tnum=0;
        cin>>t[0]>>t[1];
        if(t[0].size()!=t[1].size()){
            cout<<0<<'\n';
            continue;
        }
        tha[0].reserve(t[0].size());
        tha[1].reserve(t[1].size());
        // printf("Debug:%d %d\n",t[0].size(),t[1].size());
        pair<int,int> tdif;
        tdif.first=-1;
        for(int j=0;j<t[0].size();j++){
            if(t[0][j]!=t[1][j]){\
                tnum++;
                if(tdif.first==-1) tdif.first=j;
                tdif.second=j; 
            }
        }
        for(int j=0;j<=1;j++){
            int tmp=0;
            for(int k=0;k<t[j].size();k++){
                tmp=(1ll*tmp*BASE+t[j][k]-'a')%MOD;
                tha[j].push_back(tmp);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dif[i].second-dif[i].first!=tdif.second-tdif.first||s[i][0].size()>t[0].size()||dnum[i]!=tnum){
                continue;
            }
            // printf("chk:");
            // cout<<s[i][0]<<'\n'<<s[i][1]<<'\n'<<t[0]<<'\n'<<t[1]<<'\n';
            if(tdif.first<dif[i].first) continue;
            if(t[0].size()-tdif.second<s[i][0].size()-dif[i].second) continue;
            // cerr<<"1\n";
            if(Get(s[i][0],ha[i][0],dif[i].first,dif[i].second)!=Get(t[0],tha[0],tdif.first,tdif.second)) continue;
            // cerr<<"2\n";
            if(Get(s[i][1],ha[i][1],dif[i].first,dif[i].second)!=Get(t[1],tha[1],tdif.first,tdif.second)) continue;
            // cerr<<"3\n";
            if(Get(s[i][0],ha[i][0],0,dif[i].first)!=Get(t[0],tha[0],tdif.first-dif[i].first,tdif.first)) continue;
            // cerr<<"4\n";
            if(Get(s[i][0],ha[i][0],dif[i].second,s[i][0].size()-1)!=Get(t[0],tha[0],tdif.second,tdif.second+(s[i][0].size()-dif[i].second-1))) continue;
            ans++;
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // FileIO::Test("replace/replace3");
    FileIO::File("replace");
    int t=1;
    // scanf("%d",&t);
    while(t--){
        Work();
    }
    clog<<clock()*1.0/CLOCKS_PER_SEC;
    return 0;
}
/*
g++ test.cpp -o test -fsanitize=address,undefined -g
g++ test.cpp -o test -O2
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/