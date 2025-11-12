#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,num;
int ay[105];
bool f=0;
bool cmp(int a,int b){
    return a>b;
}
void dg(int x,int y,int n){
    if (ay[n]==num) {
        f=1;
        printf("%d %d",x+1,y+1);
    }
    if (f==1) return ;
    if (x%2==0) {
        int ny=y+1;
        if (ny>=m) dg(x+1,y,n+1);
        else dg(x,ny,n+1);
    }
    else {
        int ny=y-1;
        if (ny<0) dg(x+1,y,n+1);
        else dg(x,ny,n+1);
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=0;i<n*m;i++) scanf("%d",&ay[i]);
    num=ay[0];
    sort(ay,ay+n*m,cmp);
    dg(0,0,0);
    return 0;
}
