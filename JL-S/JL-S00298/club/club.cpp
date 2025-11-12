#include<bits/stdc++.h>
using namespace std;
const int N=10001;
int a[N], b[N], c[N];
int f[N][N]={};
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>a[i]>>b[i]>>c[i];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=3; j++){
				int x=f[i-1][j]+a[i], y=f[i-1][j]+b[i], z=f[i-1][j]+c[i];
				f[i][j]=max(max(x, y), z);
            }
        }
        cout<<f[n][3]<<'\n';
    }

    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
