/*
get sequence a,
let xor(l,r)=a[l]^a[l+1]^...^a[r],
find the most l,r are not crossed and xor(l,r)=k

1st, find all valid (l,r) to xor it is k
2nd, use tanxin
    sort with the smallest r, then search all of them
but how to find them?
em, maybe we can use the power of enum
  to get the 1~12 tasks
ohhhhhhhhh then we have 60 pts!!!!!!
go go go go go go go go go go go go go go go go go go go go go go go go go go go go go go
gosh just a 2e5 can make it fake, but our 60 pts is available, maybe i can find the solution later
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define INIT std::ios::sync_with_stdio(false),\
    std::cin.tie(0),std::cout.tie(0);
namespace AC{
    #define ll long long
    const int MAXN=2e5;
    struct Segment{
        Segment()=default;
        Segment(int l__=0,int r__=0):
            l{l__},r{r__} {}
        int l,r;
        bool operator<(const Segment& other) const{
            if(r==other.r) return l<other.l;
            return r<other.r;
        }
    };
    int n,k,a[MAXN+5],sum[MAXN+5],ans;
    std::vector<Segment>seg;
    inline int GetXor(int l,int r){
        return sum[r]^sum[l-1];
    }
    void Init(),PreSolve(),Input(),Solve(),Answer(),ACit();
}
int main(){
    AC::ACit();
    return 0;
}
void AC::Init(){
    INIT;
    freopen("xor.in" ,"r",stdin );
    freopen("xor.out","w",stdout);
}
void AC::PreSolve(){}
void AC::Input(){
    std::cin>>n>>k;
    for(int i=1;i<=n;i++) std::cin>>a[i];
}
void AC::Solve(){
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++){
            if(GetXor(l,r)==k) seg.push_back({l,r});
        }
    std::sort(seg.begin(),seg.end());
    int maxright=0;
    for(auto se:seg){
        if(se.l<=maxright) continue;
        maxright=se.r,ans++;
    }
}
void AC::Answer(){
    std::cout<<ans;
}
void AC::ACit(){
    Init();
    int T=1;
    //std::cin>>T;
    while(T--){
        PreSolve();
        Input();
        Solve();
        Answer();
    }
}