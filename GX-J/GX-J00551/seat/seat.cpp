#include<bits/stdc++.h>
using namespace std;
int a[110],n,m;
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin>>n>>m;
    for(int i = 1 ; i <= n*m ; i++) cin>>a[i];
    int ri = a[1] , rn = 1;
    for(int j = 1 ; j <= n*m ; j++){
        int t = 1;
        for(int i = 1 ; i <= n*m ; i++){
            t = 0;
            if(a[i+1]>a[i]) swap(a[i],a[i+1]);
        }
        if(t == 1) break;
    }
    for(int i = 1 ; i <= n*m ; i++){
        if(a[i] == ri){
            rn = i;
            break;
        }
    }

    int i = 1,b=0;
    for(int c = 1 ; c <= n ; c++){
        if(b == 1) break;
        if(c%2==1){
            for(int r = 1 ; r <= m ; r++){
                if(i == rn){
                    cout<<c<<' '<<r;
                    b=1;
                    break;
                }
                i++;
            }
        }else{
            for(int r = m ; r >= 1 ; r--){
                if(i == rn){
                    cout<<c<<' '<<r;
                    b=1;
                    break;
                }
                i++;
            }
        }
    }

    return 0;
}
