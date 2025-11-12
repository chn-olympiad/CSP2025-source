#include <bits/stdc++.h>
using namespace std;

struct people{

    int s;
    int idx;
    bool operator < (people A) const{
        return s>A.s;
    }

};

int n, m;

people s[110];

int main(){

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n*m; i++){
        scanf("%d", &s[i].s);
        s[i].idx=i;
    }
    sort(s+1, s+n*m+1);
    int a=1;
    for(; s[a].idx!=1; a++);
    if(a%n==0){
        if((a/n)%2==0){
            printf("%d %d", a/n, 1);
        }else{
            printf("%d %d", a/n, n);
        }
    }else{
        if((a/n+1)%2==0){
            printf("%d %d", a/n+1, n-a%n+1);
        }else{
            printf("%d %d", a/n+1, a%n);
        }
    }
    printf("\n");

    return 0;

}
