#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a;i <= b;i++)
#define dep(i,a,b) for(int i = a;i >= b;i--)
using namespace std;
int n,m,r;
int a[105];
int seat[15][15];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> r;
    a[1] = r;
    rep(i,2,n*m){
        cin >> a[i];
    }
    sort(a+1,a+1+(n*m),cmp);
    int k = 0;
    rep(i,1,m){
        if(i % 2 == 1){
            rep(j,1,n){
                if(a[++k] == r){
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }else{
            dep(j,n,1){
                if(a[++k] == r){
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }

    }
    return 0;
}
