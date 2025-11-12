#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[110];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    r = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    int id = 0;
    for(int i = 1;i <= n;i++){
        if(i % 2 == 1){
            for(int j = 1;j <= m;j++){
                    ++id;
                if(a[id] == r){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
        else{
            for(int j = m;j >= 1;j--){
                ++id;
                if(a[id] == r){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }

    }
    return 0;
}
