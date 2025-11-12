#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],r;
bool b(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    cin >> r;
    for(int i=0;i<n*m-1;i++){
        cin >> a[i];
    }
    sort(a,a+n*m-1,b);
    for(int i=0;i<n*m;i++){
        if(r>a[i]){
            cout << (i/n)+1 << ' ';
            if(((i/n)+1)%2==1){
                cout << i%n+1;
            }else{
                cout << n-(i%n);
            }
            break;
        }
    }
    return 0;
}
