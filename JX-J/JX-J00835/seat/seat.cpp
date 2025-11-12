#include <bits/stdc++.h>

using namespace std;

int lst[100];

bool cmp(int x, int y){
    return x>y;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, a=1, b=1;
    bool f;
    int sc;
    cin>>n>>m;
    if(n==1){
        f=0;
    }else{
        f=1;
    }
    for(int i=0; i<n*m; i++){
        cin>>lst[i];
    }
    sc=lst[0];
    sort(lst, lst+n*m, cmp);
    for(int i=0; i<n*m; i++){
        if(lst[i]==sc){
            cout<<b<<" "<<a;
            break;
        }
        if(f==0&&(a==1||a==n)){ // right
            b++;
            if(n>1){
                f=1;
            }
        }else if(b%2==1){ // down
            a++;
            f=0;
        }else{ // up
            a--;
            f=0;
        }
    }
    return 0;
}
