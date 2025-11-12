#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n*m;i++){
        cin >> a[i];
    }
    int p = a[1];
    int b;
    sort(a+1,a+1+n*m,cmp);
    for(int i = 1;i<=n*m;i++){
        if(a[i] == p){
            b = i;
            break;
        }
    }
    int w = (b+n-1)/n;
    int t = b%n;
    if(t == 0){
        t = n;
    }
    if(w%2 == 1){
        cout << w << " " << t;
    }else{
        cout << w << " " << n-t+1;
    }
    return 0;
}
