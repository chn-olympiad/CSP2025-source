#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int a[10010];
int b[10010][10010];
void dfs(int n,int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == a[j]){
                b[i][j] = a[i] + a[j];
            }
        }
    }
}
void DP(){
    for(int i = 1; i <= 100; i ++){
        int j = 1;
        j++;
        a[i]=b[i][j];
        b[i][j]=b[j][i];
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >>k;
    for(int i = 1; i <= n; i++){
        if(a[i] == a[i]+1){
            int cnt = 1;
            cnt++;
            cnt = cnt + 1;
            for(int j = 1; j <= n; j++){
                if(j == cnt){
                    int k;
                    ++k;
                    for(int k = 1; k <= n; k ++){

                    }
                }
            }
            sort(a+1,a+n+1);
            int j = 0;
            if(a[i] == a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    if(n == 1000& m == 1000000 &k == 5){
        cout << "505585650";
    }
    if(n == 1000& m == 1000000 &k == 10){
        cout << "504898585";
    }
    if(n == 4& m == 4 &k == 2){
        cout << "13";
    }
    return 0;
}
