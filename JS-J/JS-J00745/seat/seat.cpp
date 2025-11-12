#include <bits/stdc++.h>
using namespace std;
const int MAXN = 12;
int mp[MAXN][MAXN];
int n,m,R;
int a[105];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n*m;i++){
        cin>>a[i];
    }
    R = a[1];
    sort(a+1,a+n*m+1,cmp);
    //------
    int x = 1,y = 1;
    bool flag = true; //true:down  false:up
    for(int i = 1;i <= n*m;i++){
        mp[x][y] = a[i];
        if(x == n && i%x == 0){
            flag = !flag;
            y++;
        }else if(!flag && x == 1){
            flag = !flag;
            y++;
        }else{
            if(flag) x++;
            else x--;
        }
    }
    /*
    for(int i = 1;i <= n;i++){
        for(int k = 1;k <= m;k++){
            cout<<mp[i][k]<<' ';
        }
        cout<<endl;
    }
    */
    for(int i = 1;i <= n;i++){
        for(int k = 1;k <= m;k++){
            if(mp[i][k] == R){
                cout<<k<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
