#include "bits/stdc++.h"
using namespace std;


const int N = 100000;

int t;
int a[4][N + 10];
int p[4][N + 10];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> t;

    for(int i = 1;i <= t;i++){
        memset(p,0,sizeof(p));
        int n,m,ps;
        int cnt = 0;

        cin >> n;
        m = n / 2;

        for(int j = 1;j <= n;j++){
            int mx = INT_MIN;
            for(int k = 1;k <= 3;k++){
                cin >> a[k][j];
                if(a[k][j] >= mx){
                    mx = a[k][j];
                    ps = k;
                }
            }
            if(p[ps][j] <= m && a[ps][j] != 1){
                p[ps][j]++;
                cnt += a[ps][j];
            }
        }
        cout << cnt << endl;
    }

    return 0;
}

/*
const int N = 100000;

int t;
int a[4][N + 10];
int p[4];
int s[4];
bool f[4][N + 10];

/*
int dfs(int x,int y,int q[]){
    int c = 0;

    for(int i = 1;i <= x;i++){
        for(int j = 2;j <= x;j++){
            if(q[i] + q[j] >= c){
                c = q[i] + q[j];
            }
        }
    }

    return c;
}


int main(){
//  freopen("club.in","r",stdin);
//  freopen("club.out","w",stdout);
    cin >> t;

    for(int i = 1;i <= t;i++){
        memset(p,0,sizeof(p));
        memset(s,0,sizeof(s));
        memset(f,false,sizeof(f));
        int n,m;
        int cnt = 0;

        cin >> n;
        m = n / 2;

        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= 3;k++){
                cin >> a[k][j];
            }
        }

        for(int k = 1;k <= 3;k++){
            int ad[100001];
            for(int j = 1;j <= n;j++){
               ad[j] = a[k][j];
            }
            //s[k] = dfs(n,m,ad[]);
            sort(ad,ad + n);
            for(int i = m;i < n;i++){
                s[k] += ad[i];
            }
        }

        for(int k = 1;k <= 3;k++){
            if(s[k] >= cnt){
                cnt = s[k];
            }
        }

        for(int )

        cout << cnt << endl;
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
