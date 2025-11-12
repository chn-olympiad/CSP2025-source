#include <bits/stdc++.h>
//CSP-J RP++
//CSP-S(NEXT YEAR) RP++
using namespace std;
int a[10005];
int n,m,rk,sc;
int c,r;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("r","seat.in",stdin);
    freopen("w","seat.out",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    sc=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==sc) {rk=i;break;}
    }
    if((rk%n)!=0) c=(rk/n)+1;
    else c=rk/n;
    if(c%2==0&&rk%n!=0) r=n-(rk%n)+1;
    if(c%2!=0&&rk%n!=0) r=rk%n;
    if(c%2==0&&rk%n==0) r=1;
    if(c%2!=0&&rk%n==0) r=n;
    printf("%d %d",c,r);
    return 0;
}
