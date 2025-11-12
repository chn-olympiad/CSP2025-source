#include <bits/stdc++.h>
using namespace std;
int a[10001][10001];
int b[10001];
int n,m,o;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int sum = n*m;
    for(int i = 1;i <= sum;i++) cin >> b[i];
    int ans = b[1];
    sort(b+1,b+sum+1,cmp);
    for(int i = 1;i <= n;i++){
        if(ans == b[i]){
            o = i;
        }
    }
    int i = o / n + 1;
    int j;
    if(o % m == 0 && i % 2 == 0){
        j = 1;
    }else if(o % m == 0){
        j = n;
    }else{
        j = o % m;
    }
    cout << i << " " << j;
    return 0;
}
