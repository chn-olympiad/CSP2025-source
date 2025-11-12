#include<iostream>
#include<cstdio>
#include<queue>
#include<bitset>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define IFD if(1)
int n,m,k;
long long jc[505];
const long long M=998244353;
string s;
int pat[505]; // patience
bool spA=1;
bitset<505> used;
int days[505];
long long bans=0;
inline bool check(){
    int failcnt=0;
    for(int i=1;i<=n;++i){
        int man=days[i];
        // printf("day %d man %d pat %d failed %d\n",i,days[i],pat[man],failcnt);
        if(s[i-1]=='0'||failcnt>=pat[man]){
            failcnt++;
        }
    }
    if(failcnt>n-m)return false;
    return 1;
}
void DFS(int day,int id){
    days[day]=id;
    if(day==n){
        bans=(bans+check())%M;
    }
    used[id]=1;
    for(int i=1;i<=n;++i){
        if(used[i])continue;
        DFS(day+1,i);
    }
    used[id]=0;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    
    //freopen("empolo.out","w",stdout);
    cin >> n >> m;
    cin >> s;

    for(int i=0;i<n;++i){
        if(s[i]=='0')spA=0;
    }
    /*
    jc[1]=1;
    for(int i=2;i<=n;++i){
        jc[i]=(jc[i-1]*i)%M;
        // IFD if(i<=19)printf("%d! =%d\n",i,jc[i]);
    }*/
        int an=n;
        for(int i=1;i<=n;++i){
            scanf("%d",pat+i);
            if(pat[i]==0)an--;
        }
    // 1~4 burteforce: DFS order
    DFS(0,0);
    printf("%lld\n",bans);
    // if(spA){
        // printf("%lld\n",jc[an-1]);
        // return 0;
    // }
}