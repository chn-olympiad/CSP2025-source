#include<bits/stdc++.h>
using namespace std;
int n,m,score[105],r,seat[15][15],t,rs;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++) cin >> score[i];
    r = score[1];
    sort(score,score+n*m+1);
    for(int i = 1;i <= m;i++){
        if(i % 2 == 1){
            for(int j = 1;j <= n;j++){
                t++;
                seat[j][i] = t;
            }
        }
        if(i % 2 == 0){
            for(int j = n;j >= 1;j--){
                t++;
                seat[j][i] = t;
            }
        }
    }
    for(int i = 1;i <= n*m;i++) 
        if(score[i] == r) rs = i;
   for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++)
            if(seat[i][j] == n*m+1-rs) cout << j << " " << i << endl;
    }
    return 0;
}