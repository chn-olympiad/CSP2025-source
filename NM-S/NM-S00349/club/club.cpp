#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][5], vis1, vis2, vis3, vis[100005][5], num1, num2, num3, ans, sum;
void mfind(int u){
    if(num1 == n / 2){
        vis1 = 1;
    }
    if(num2 == n / 2){
        vis2 = 1;
    }
    if(num3 == n / 2){
        vis3 = 1;
    }
    int mmax = 0, maxi, maxj;
    if(u == n){
        return ;
    }else{
        for(int i = 0;i < n;++i){
            for(int j = 0;j < 3;++j){
                if(vis1 && j == 0){
                    continue;
                }else if(vis2 && j == 1){
                    continue;
                }else if(vis3 && j == 2){
                    continue;
                }else if(vis[i][j]){
                    continue;
                }
                if(mmax < a[i][j]){
                    mmax = a[i][j];
                    maxi = i;
                    maxj = j;
                }
            }
        }
        vis[maxi][maxj] = 1;
        if(maxj == 0){
            num1++;
        }else if(maxj == 1){
            num2++;
        }else{
            num3++;
        }
        ans += a[maxi][maxj];
        mfind(u + 1);
    }
}
void dfs(int member, int c1, int c2, int c3){
    if(member == n){
        ans = max(ans, sum);
        return ;
    }else{
        for(int i = 0;i < 3;++i){
            if(i == 0 && c1 == n / 2){
                continue;
            }
            if(i == 1 && c2 == n / 2){
                continue;
            }
            if(i == 2 && c3 == n / 2){
                continue;
            }
            sum += a[member][i];
            if(i == 0){
                dfs(member + 1, c1 + 1, c2, c3);
            }else if(i == 1){
                dfs(member + 1, c1, c2 + 1, c3);
            }else{
                dfs(member + 1, c1, c2, c3 + 1);
            }
            sum -= a[member][i];
        }
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin  >>  t;
    while(t--){
        cin  >>  n;
        if(n <= 16){
            for(int i = 0;i < n;++i){
                for(int j = 0;j < 3;++j){
                    cin  >>  a[i][j];
                }
            }
            dfs(0, 0, 0, 0);
            cout  <<  ans  <<  endl;
            ans = 0;
            sum = 0;
        }else{
            for(int i = 0;i < n;++i){
                for(int j = 0;j < 3;++j){
                    cin  >>  a[i][j];
                }
            }
            mfind(0);
            cout  <<  ans  <<  endl;
            vis1 = 0, vis2 = 0, vis3 = 0, num1 = 0, num2 = 0, num3 = 0, ans = 0;
            for(int i = 0;i < n;++i){
                for(int j = 0;j < 3;++j){
                    vis[i][j] = 0;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
