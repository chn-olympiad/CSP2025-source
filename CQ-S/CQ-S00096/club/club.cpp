#include<bits/stdc++.h>
using namespace std;
struct node{int x, v;}a[100005];
int T, n, bar[3], len, ans, ve[100005];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;ans=0;
        for(int i=1; i<=n; i++){
            int maxx=-1, smax=-1, p=-1;
            for(int j=0; j<3; j++){
                int x;cin >> x;
                if(maxx<x)smax=maxx, maxx=x, p=j;
                else if(smax<x)smax=x;
            }
            a[i]={maxx-smax, p};ans+=maxx;
            bar[p]++;
        }int now=0, smaxx=-1;
        for(int i=0; i<3; i++)if(bar[i]>smaxx)smaxx=bar[i], now=i;
        for(int i=1; i<=n; i++)if(a[i].v==now)ve[++len]=a[i].x;
        sort(ve+1, ve+1+len);
        for(int i=1; i<=smaxx-(n/2); i++)ans-=ve[i];
        cout << ans << '\n';
        len=0;memset(bar, 0, sizeof(bar));
    }return 0;
}