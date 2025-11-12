#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,ansy,ansx;
int a[110],s[15][15];
void init(){
    int cnt=0;
    for(int j = 1;j<=m;j++){
        if(j&1){
            for(int i = 1;i<=n;i++){
                s[i][j] = ++cnt;
            }
        }else{
            for(int i = n;i>=1;i--){
                s[i][j] = ++cnt;
            }
        }
    }
}
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    init();
    for(int i = 1;i<=n*m;i++){
        cin >> a[i];
    }
    k = a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i<=n*m;i++){
        if(a[i] == k){
            x = i;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i][j] == x){
                ansy = j;
                ansx = i;
            }
        }
    }
    cout << ansy << " " << ansx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}