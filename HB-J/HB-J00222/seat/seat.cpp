#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define INIT std::ios::sync_with_stdio(false),\
    std::cin.tie(0),std::cout.tie(0);
namespace AC{
    #define ll long long
    #define pii std::pair<int,int>
    const int MAXN=10;
    int n,m;
    int score[MAXN*MAXN+5],a[MAXN*MAXN+5];
    inline pii GetSeatID(int k){
        int rank=1,x=1,y=1;
        int dir=1;
        do{
            rank++;
            x+=dir;
            if(x>n&&dir==1) y++,dir=-1,x--;
            else if(x<1&&dir==-1) y++,dir=1,x++;
        }while(rank<=n*m&&rank<k);
        return std::make_pair(x,y);
    }
    void Init(),PreSolve(),Input(),Solve(),Answer(),ACit();
}
int main(){
    AC::ACit();
    return 0;
}
void AC::Init(){
    INIT;
    freopen("seat.in" ,"r",stdin );
    freopen("seat.out","w",stdout);
}
void AC::PreSolve(){
    for(int i=1;i<=MAXN*MAXN;i++) a[i]=i;
}
void AC::Input(){
    std::cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        std::cin>>score[i];
    }
}
void AC::Solve(){
    std::sort(a+1,a+n*m+1,[](int x,int y){return score[x]>score[y];});
}
void AC::Answer(){
    for(int i=1;i<=n*m;i++){
        if(a[i]==1){
            pii ID=GetSeatID(i);
            std::cout<<ID.second<<' '<<ID.first;
            break;
        }
    }
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