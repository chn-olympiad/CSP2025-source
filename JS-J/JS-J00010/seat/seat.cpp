#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 105;
int a[N];


bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++){
        cin >> a[i];
    }
    int x = a[1];
    sort(a+1,a+n*m+1,cmp);
    int pos;
    for(int i = 1; i <= n*m; i++){
        if(a[i] == x) pos = i;
    }
    int ret = pos % n;
    int row = pos / n + (ret != 0);
    int line;
    if(row % 2 == 1){
        if(ret == 0){
            line = n;
        }
        else{
            line = ret;
        }
    }
    else{
        if(ret == 0){
            line = 1;
        }
        else{
            line = n + 1 - ret;
        }
    }
    cout << row << " " << line;
    return 0;
}
