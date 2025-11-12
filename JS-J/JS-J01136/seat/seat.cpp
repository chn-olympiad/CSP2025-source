#include <bits/stdc++.h>
using namespace std;
int a[207];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int ct=n*m;
    for(int i=1; i<=ct; ++i){
        scanf("%d", a+i);
    }
    int r=a[1], c=1;
    sort(a+1, a+1+ct);
    for(int i=ct; i>=1; --i){
        if(a[i]==r){
           break;
        }
        ++c;
    }
    int l=c/n+1, h=c%n;
    if((l%2==1  &&h!=0) || (l%2==0 && h==0)){
        if(h==0){
            h=n;
            l-=1;
        }
    }else{
        if(h==0){
            h=1;
            l-=1;
        }else{
            h=n-h+1;
        }
    }
    printf("%d %d", l, h);
}
