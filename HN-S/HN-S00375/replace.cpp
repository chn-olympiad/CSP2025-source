#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define All(v) v.begin(),v.end()
#define lowbit(x) (x&-x)
using ull=unsigned long long;
using pii=pair<int,int>;
const int N=5e6+5;
const ull base=13131;
int n,q,L[200005],R[200005],B;
string s[200005][2],t[200005][2];
ull hs1[N],hs2[N],w[200005][2],pb[N];
struct info{
    int len1,len2;
    ull hss,hst,hs1,hs2;
};
vector<info> v[200005];
vector<int> l;
int ans[200005];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i][0]>>s[i][1];
    for(int i=1;i<=q;i++){
        cin>>t[i][0]>>t[i][1];
        if(t[i][0].size()!=t[i][1].size()){ans[i]=0;continue;}
        for(int j=0;j<t[i][0].size();j++){
            if(t[i][0][j]!=t[i][1][j]){L[i]=j;break;}
        }
        for(int j=t[i][0].size()-1;~j;j--){
            if(t[i][0][j]!=t[i][1][j]){R[i]=j;break;}
        }
        l.emplace_back(R[i]-L[i]+1);
        for(int j=L[i];j<=R[i];j++){
            w[i][0]=w[i][0]*base+(t[i][0][j]-'a'+1);
            w[i][1]=w[i][1]*base+(t[i][1][j]-'a'+1);
        }
    }
    sort(All(l));l.erase(unique(All(l)),l.end());
    for(int i=1;i<=n;i++){
        if(s[i][0]==s[i][1]) continue;
        pb[0]=1;
        hs1[0]=hs2[0]=0;
        for(int j=0;j<s[i][0].size();j++){
            hs1[j+1]=hs1[j]*base+(s[i][0][j]-'a'+1);
            hs2[j+1]=hs2[j]*base+(s[i][1][j]-'a'+1);
            pb[j+1]=pb[j]*base;
        }
        auto get1=[&](int l,int r)->ull{
            l++,r++;
            return hs1[r]-hs1[l-1]*pb[r-l+1];
        };
        auto get2=[&](int l,int r)->ull{
            l++,r++;
            return hs2[r]-hs2[l-1]*pb[r-l+1];
        };
        int l=0,r=s[i][0].size()-1;
        for(int j=0;j<s[i][0].size();j++){
            if(s[i][0][j]!=s[i][1][j]){l=j;break;}
        }
        for(int j=s[i][0].size()-1;~j;j--){
            if(s[i][0][j]!=s[i][1][j]){r=j;break;}
        }
        v[r-l+1].push_back((info){l,s[i][0].size()-1-r,get1(l,r),get2(l,r),get1(0,l-1),get1(r+1,s[i][0].size()-1)});
        // cout<<"!!!!!"<<i<<" "<<get1(0,l-1)<<" "<<get1(r+1,s[i][0].size()-1)<<" "<<get1(l,r)<<" "<<get2(l,r)<<endl;
    }
    for(int x:l) sort(All(v[x]),[&](info A,info B){return A.len1<B.len1;});
    for(int i=1;i<=q;i++){
        if(t[i][0].size()!=t[i][1].size()){puts("0");continue;}
        int len=R[i]-L[i]+1;
        hs1[0]=0;
        for(int j=0;j<t[i][0].size();j++) hs1[j+1]=hs1[j]*base+(t[i][0][j]-'a'+1);
        auto get=[&](int l,int r)->ull{l++,r++;return hs1[r]-hs1[l-1]*pb[r-l+1];};
        int res=0;
        for(int j=0;j<v[len].size();j++){
            if(v[len][j].len1>L[i]) break;
            if(v[len][j].len1<=L[i]&&v[len][j].len2<=t[i][0].size()-R[i]-1
            &&v[len][j].hss==w[i][0]&&v[len][j].hst==w[i][1]&&
            v[len][j].hs1==get(L[i]-v[len][j].len1,L[i]-1)&&
            v[len][j].hs2==get(R[i]+1,R[i]+v[len][j].len2)) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}