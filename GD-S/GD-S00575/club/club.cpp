#include<bits/stdc++.h>
using namespace std;
const int N = 10010;

int t;
int n,m;
int sat[N][4],anslst[N];
int c[4];
long long bestans = 0;



int solve2(){
    long long ans = 0;
    for(int i = 1; i <= n; i++) ans += sat[i][anslst[i]];
    bestans = max(ans,bestans);
}


void solve1(int d,int now){
    if(now > d) solve2();
    else{
        if(c[1] < m){
            c[1]++;
            anslst[now] = 1;
            solve1(d,now+1);
            c[1]--;
        }
        if(c[2] < m){
            c[2]++;
            anslst[now] = 2;
            solve1(d,now+1);
            c[2]--;
        }
        if(c[3] < m){
            c[3]++;
            anslst[now] = 3;
            solve1(d,now+1);
            c[3]--;

        }
   }
   return;
}







int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%d",&t);


    while(t--){

        bestans = 0;
        n = 0;
        memset(c,sizeof(c),0);

        scanf("%d",&n);
        m = n/2;

        for(int i = 1; i <= n; i++)
            scanf("%d%d%d",&sat[i][1],&sat[i][2],&sat[i][3]);

        solve1(n,1);

        printf("%d\n",bestans);


    }


    return 0;
}
