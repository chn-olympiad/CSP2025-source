#include<bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int a, int b){
    return a>b;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int k=a[0], p;
    sort(a, a+(m*n), cmp);
    for(int i=0;i<m*n;i++){
        if(a[i]==k){
            p=i+1;
        }
    }
    int x, y;
    if(p%n==0){
        x=p/3;
    }
    else{
        x=p/3+1;
    }
    if(x%2==1){
        y=p%n;
        if(y==0){
            y=n;
        }
    }
    else{
        y=p%n;
        if(y==0){
            y=n;
        }
        y=n+1-y;
    }
    cout<<x<<" "<<y;
    return 0;
}
