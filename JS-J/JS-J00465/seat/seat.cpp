#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mx=200;
int a[mx];
int n,m;
int x,ind;
inline bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&a[1]);
    x=a[1];
    for(int i=2;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n*m+1);
    int ind=lower_bound(a+1,a+n*m+1,x)-a;
    ind=n*m-ind+1;
    int x=(ind-1)/n+1;
    int y=(ind-1)%n+1;
    if(x%2==0) y=n-y+1;
    printf("%d %d",x,y);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
