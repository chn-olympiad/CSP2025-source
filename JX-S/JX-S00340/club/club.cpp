#include <iostream>
#include <cstdio>
using namespace std;
int a[5][3][100003]={0};
int d1=0,d2=0,d3=0;
int n[5]={0},ans[5]={0};
int temp=0;
void dfs(int z,int x,int y){
    if(x==1) d1++;
    if(x==2) d2++;
    if(x==3) d3++;
    temp+=a[z][x][y];
    if(d1 <= n[z]/2 && d2 <= n[z]/2 && d3 <= n[z]/2 && temp > ans[z]){
        ans[z]=temp;
    } else {
        if(x==1) d1--;
        if(x==2) d2--;
        if(x==3) d3--;
        if(d1 > n[z]/2 || d2 > n[z]/2 || d3 > n[z]/2) {
         return ;
        }
    }
    if(y<n[z]){
        for(int i=1;i <= 3 ; i++){
            dfs(z,i,y+1);
            temp-=a[z][i][y+1];
        }
    }
    if(x==1) d1--;
    if(x==2) d2--;
    if(x==3) d3--;
    temp-=a[z][x][y];
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t ;
    for (int i = 1;i <= t;i++ ){
        cin >> n[i];
        for(int j = 1; j <= n[i]; j++){
            cin >> a[i][1][j];
            cin >> a[i][2][j];
            cin >> a[i][3][j];
        }
    }
    for(int i=1; i <= t;i++){
        dfs(i,0,0);
        cout << ans[i] << endl;
    }
    return 0;
}
