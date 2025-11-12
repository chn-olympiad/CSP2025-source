#include<bits/stdc++.h>
using namespace std;
int m,n,a[11][11],b[110],x;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> m >> n;
    for(int i = 1;i <= m * n;i++){
        cin >> b[i];
    }
    x = b[1];
    sort(b + 1,b + m * n + 1,cmp);
    int k = 0;
    for(int i = 1;i <= n;i++){
        if(i % 2 == 1){
            for(int j = 1;j <= m;j++){
                k++;
                if(b[k] == x){
                    cout << i << ' ' << j;
                }
            }
        }else{
            for(int j = m;j >= 1;j--){
                k++;
                if(b[k] == x){
                    cout << i << ' ' << j;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
