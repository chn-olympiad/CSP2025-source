#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, pos, a1;
const int N=1e3+5;
int a[N];
bool cmp(int x, int y) {
    return x>y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++) scanf("%d", &a[i]);
    a1=a[1];
    sort(a+1, a+n*m+1, cmp);
    for(int i=1; i<=n*m; i++) {
        if(a[i]==a1) { pos=i; break; }
    }
    int ln, le;
    le=(pos+n-1)/n;
    if(le%2==1) {
        ln=pos%n;
        if(pos%n==0) ln=n;
    }
    else if(le%2==0) {
        ln=n-(pos%n)+1;
        if(pos%n==0) ln=1;
    }
    cout<<le<<" "<<ln;
    return 0;
}

/*
3 3
94 95 96 97 98 99 100 93 92
*/




