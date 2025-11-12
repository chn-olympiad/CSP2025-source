#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ULL unsigned long long
#define plu pair<long long,ULL>
#define piu pair<int,ULL>
#define PII array<int,2>
#define i128 __int128
#define make(a,b) make_pair(a,b)
const int maxn=2e5+5,maxm=5e6+5,base=233,bus=1e6+7;
const long long mod=1000000000000000001ll;
map<plu,int> od;
map<piu,int> ct,vis;
unordered_map<ULL,int> cor,clr;
int n,q,cod;
string s1,s2,s3,t1,t2;
vector<string> Jes[maxn];
vector<int> L[maxn];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        int l=-1,r=-1,len=s1.length();
        for(int j=0;j<len;j++){
            if(s1[j]!=s2[j]){
                if(l==-1)l=j;
                r=j;
            }
        }
        if(l==-1)continue;
        ULL has=0;
        for(int j=l;j<=r;j++)has=has*base+(s1[j]-'a'+1);
        for(int j=l;j<=r;j++)has=has*base+(s2[j]-'a'+1);
        long long sah=0;
        for(int j=l-1;j>=0;j--){
            sah=((i128)sah*bus+(s1[j]-'a'+1))%mod;
        }
        if(od.find(make(sah,has))==od.end()){
            od[make(sah,has)]=++cod;
        }
        int now=od[make(sah,has)];
        s3="";
        for(int j=r+1;j<len;j++)s3+=s1[j];Jes[now].emplace_back(s3);
    }
    //预处理贡献
    for(int i=1;i<=cod;i++){
        static PII tak[maxn];
        int top=0,len=Jes[i].size();
        for(int j=0;j<len;j++){
            tak[++top]=PII{(int)Jes[i][j].length(),j};
        }
        sort(tak+1,tak+1+top);
        cor=clr;
        cor.clear();
        for(int id=1;id<=top;id++){
            int j=tak[id][1],sz=tak[id][0];if(L[i].empty()||L[i].back()!=sz)L[i].emplace_back(sz);
            ULL has=0;
            int sig=0,premax=0;
            for(int k=0;k<sz;k++){
                sig+=cor[has];
                premax=max(premax,ct[make(i,has)]),ct[make(i,has)]=premax,has=has*base+(Jes[i][j][k]-'a'+1);
            }
            cor[has]++,sig+=cor[has],premax=max(premax,sig),ct[make(i,has)]=premax;
        }
    }
    //计算答案
    while(q--){
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            cout<<0<<endl;
            continue;
        }
        int l=-1,r=-1,len=t1.length();
        for(int i=0;i<len;i++){
            if(t1[i]!=t2[i]){
                if(l==-1)l=i;
                r=i;
            }
        }
        ULL has=0;
        for(int i=l;i<=r;i++)has=has*base+(t1[i]-'a'+1);
        for(int i=l;i<=r;i++)has=has*base+(t2[i]-'a'+1);
        long long sah=0;
        int ans=0;
        static ULL H[maxm];
        int m=len-r-1;
        for(int i=1;i<=m;i++){
            H[i]=H[i-1]*base+(t1[r+i]-'a'+1);
        }
        for(int j=l-1;j>=-1;j--){
            int now=od[make(sah,has)];
            if(now and L[now].size()){
                int ql=0,qr=L[now].size()-1,qmid=0,res=0;
                while(ql<=qr){
                    qmid=(ql+qr)>>1;
                    if(L[now][qmid]<=m and ct.find(make(now,H[L[now][qmid]]))!=ct.end()){
                        res=ct[make(now,H[L[now][qmid]])];
                        ql=qmid+1;
                    }else{
                        qr=qmid-1;
                    }
                }
                ans+=res;
            }
            if(j!=-1)sah=((i128)sah*bus+(t1[j]-'a'+1))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}