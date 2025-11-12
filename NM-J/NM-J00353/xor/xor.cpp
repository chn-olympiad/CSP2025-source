#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    int c[n+1][n];
    int ans = 0;
    for(int i = 0;i < n;i++){
        c[0][i] = 0;
        cin>>c[1][i];
        if(c[1][i] == k){
            c[2][i+1] = -1;
            c[2][i] = -1;
            ans++;
        }
    }
    for(int x = 2;x < n+1;x++){
        for(int y = x-1;y < n;y++){
            if(c[x-1][y-1] <= -1 || c[x-1][y] <= -1){
                c[x][y] = -1;
            }else if(c[x][y] <= -1 && c[x][y] >= x*-1){
                c[x][y+1] = c[x][y]-1;
            }else{
                c[x][y] = c[x-1][y]^c[x-1][y-1]^c[x-2][y-1];
                if(c[x][y] == k){
                    c[x+1][y+1] = -1;
                    c[x+1][y] = -1;
                    c[x][y+1] = -2;
                    ans++;
                }
            }
            //cout<<c[x][y]<<' ';
        }
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}
