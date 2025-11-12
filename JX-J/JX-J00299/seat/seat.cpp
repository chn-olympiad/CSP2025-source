#include <bits/stdc++.h>
using namespace std;
bool com(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[105];
    for(int i = 1;i<=n*m;i++){
        cin >> a[i];
    }
    int b = a[1];
    sort(a+1,a+n*m+1,com);
    for(int i = 1;i<= n*m;i++){
        if(a[i] == b){
            b = i;
        }
    }
    int p = (b+n-1)/n;
    int q = 0;
    if(p%2){
        if(b%n==0){
            q = n;
        }
        else{
            q = b%n;
        }
    }
    else{
        if(b%n==0){
            q=1;
        }
        else{
            q = n - (b%n) + 1;
        }
    }
    cout << p <<" "<< q;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
