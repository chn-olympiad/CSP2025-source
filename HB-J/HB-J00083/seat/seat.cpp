#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a > b;
}


int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n*m+1];
    int b[2*n+1] = {};
    for(int i = 1;i <= n*m+1;i++){
        cin >> a[i];
    }
    int ziji = a[1];
    sort(a+1,a+n*m+1,cmp);
    int k;
    for(int i = 1;i <= n*m+1;i++){
        if(a[i] == ziji){
            k = i;
        }
    }
    int h = k;
    if(h % n != 0){
        cout << h / n + 1;
    }
    else
    {
        cout << h / n;
    }
    int l = k % (2*n);
    for(int i = 1;i <= n;i++){
        b[i] = i;
    }
    for(int i = 1;i <= n;i++){
        b[n + i] = n - i + 1;
    }
    cout << " " << b[l];
    return 0;
}
