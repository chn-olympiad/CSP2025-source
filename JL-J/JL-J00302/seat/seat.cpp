#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n , m ,t ,a1;
    cin >>n >> m;
    t = n * m;
    for(int i =1;i <= t;i++){
        cin >> a[i];
    }
    int loc = 0;
    a1 = a[1];
    sort(a+1,a+t+1,cmp);
    for(int i = 1;i <= t;i++){
        if(a[i] == a1){

            loc = i;
            break;
        }
    }
    int x , y;
    if(loc % n == 0){
        x = loc / n;
    }else{
        x = loc / n + 1;
    }
    if(x % 2 == 0){
        y = n - (loc % n ) + 1;
    }else{
        y = (loc - 1) % n + 1;
    }
    cout << x <<" "<<y;
    return 0;
}
