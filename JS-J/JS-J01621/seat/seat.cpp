#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a, int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++){
        cin >> a[i];
    }
    int x = a[1],w;
    sort(a+1,a+1+n*m,cmp);
    for(int i = 1; i <= n*m; i++){
        if(a[i] == x){
            w = i;
            break;
        }
    }
    int l;
    if(w % n == 0){
        l = w/n;
    }else{
        l = w/n+1;
    }
    cout << l << " ";
    int r;
    if(l%2){
        w-=(l-1)*n;
        r = w;
    }else{
        w-=(l-1)*n;
        r = n-(w-1);
    }
    cout << r << "\n";
    return 0;
}
