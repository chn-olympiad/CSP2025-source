#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n;
int f[N][4][4];
struct club{
    int a, b, c;
}d[N];
bool cmp1(club xx,club yy){
    if(xx.a>yy.a) return 1;
    if(xx.a<yy.a) return 0;
    if(xx.b>yy.b) return 1;
    if(xx.b<yy.b) return 0;
    if(xx.c>yy.c) return 1;
    return 0;
}
bool cmp2(club xx,club yy){
    if(xx.a>yy.a) return 1;
    if(xx.a<yy.a) return 0;
    if(xx.c>yy.c) return 1;
    if(xx.c<yy.c) return 0;
    if(xx.b>yy.b) return 1;
    return 0;
}
bool cmp3(club xx,club yy){
    if(xx.b>yy.b) return 1;
    if(xx.b<yy.b) return 0;
    if(xx.a>yy.a) return 1;
    if(xx.a<yy.a) return 0;
    if(xx.c>yy.c) return 1;
    return 0;
}
bool cmp4(club xx,club yy){
    if(xx.b>yy.b) return 1;
    if(xx.b<yy.b) return 0;
    if(xx.c>yy.c) return 1;
    if(xx.c<yy.c) return 0;
    if(xx.a>yy.a) return 1;
    return 0;
}
bool cmp5(club xx,club yy){
    if(xx.c>yy.c) return 1;
    if(xx.c<yy.c) return 0;
    if(xx.a>yy.a) return 1;
    if(xx.a<yy.a) return 0;
    if(xx.b>yy.b) return 1;
    return 0;
}
bool cmp6(club xx,club yy){
    if(xx.c>yy.c) return 1;
    if(xx.c<yy.c) return 0;
    if(xx.b>yy.b) return 1;
    if(xx.b<yy.b) return 0;
    if(xx.a>yy.a) return 1;
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        int nn = n / 2, ans = -1;
        for (int i = 1; i <= n;i++)
            cin >> d[i].a >> d[i].b >> d[i].c;
        sort(d + 1, d + 1 + n,cmp1);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n;i++){
            int a[4];
            a[1]=d[i].a; a[2] = d[i].b; a[3] = d[i].c;
            for (int j = 1; j <= 3;j++){
            for (int k = 1; k <= 3;k++){
                if (f[i-1][k][j] + 1 <= nn){
                    if(f[i][j][0]<f[i-1][k][0] + a[j]){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                    if(f[i][j][0]==f[i-1][k][0] + a[j]&&k!=j){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                }
            }}
        }
        sort(d + 1, d + 1 + n,cmp2);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n;i++){
            int a[4];
            a[1]=d[i].a; a[2] = d[i].b; a[3] = d[i].c;
            for (int j = 1; j <= 3;j++){
            for (int k = 1; k <= 3;k++){
                if (f[i-1][k][j] + 1 <= nn){
                    if(f[i][j][0]<f[i-1][k][0] + a[j]){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                    if(f[i][j][0]==f[i-1][k][0] + a[j]&&k!=j){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                }
            }}
        }
        sort(d + 1, d + 1 + n,cmp3);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n;i++){
            int a[4];
            a[1]=d[i].a; a[2] = d[i].b; a[3] = d[i].c;
            for (int j = 1; j <= 3;j++){
            for (int k = 1; k <= 3;k++){
                if (f[i-1][k][j] + 1 <= nn){
                    if(f[i][j][0]<f[i-1][k][0] + a[j]){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                    if(f[i][j][0]==f[i-1][k][0] + a[j]&&k!=j){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                }
            }}
        }
        sort(d + 1, d + 1 + n,cmp4);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n;i++){
            int a[4];
            a[1]=d[i].a; a[2] = d[i].b; a[3] = d[i].c;
            for (int j = 1; j <= 3;j++){
            for (int k = 1; k <= 3;k++){
                if (f[i-1][k][j] + 1 <= nn){
                    if(f[i][j][0]<f[i-1][k][0] + a[j]){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                    if(f[i][j][0]==f[i-1][k][0] + a[j]&&k!=j){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                }
            }}
        }
        sort(d + 1, d + 1 + n,cmp5);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n;i++){
            int a[4];
            a[1]=d[i].a; a[2] = d[i].b; a[3] = d[i].c;
            for (int j = 1; j <= 3;j++){
            for (int k = 1; k <= 3;k++){
                if (f[i-1][k][j] + 1 <= nn){
                    if(f[i][j][0]<f[i-1][k][0] + a[j]){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                    if(f[i][j][0]==f[i-1][k][0] + a[j]&&k!=j){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                }
            }}
        }
        sort(d + 1, d + 1 + n,cmp6);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n;i++){
            int a[4];
            a[1]=d[i].a; a[2] = d[i].b; a[3] = d[i].c;
            for (int j = 1; j <= 3;j++){
            for (int k = 1; k <= 3;k++){
                if (f[i-1][k][j] + 1 <= nn){
                    if(f[i][j][0]<f[i-1][k][0] + a[j]){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                    if(f[i][j][0]==f[i-1][k][0] + a[j]&&k!=j){
                        f[i][j][1]=f[i-1][k][1];
                        f[i][j][2]=f[i-1][k][2];
                        f[i][j][3]=f[i-1][k][3];
                        f[i][j][j]=f[i-1][k][j]+1;
                        f[i][j][0] = f[i-1][k][0] + a[j];
                        ans = max(ans, f[i][j][0]);
                    }
                }
            }}
        }
        cout << ans << "\n";
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