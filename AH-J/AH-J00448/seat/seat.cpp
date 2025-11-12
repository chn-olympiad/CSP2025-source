#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
    int num;
    bool IsR;
}a[1005];
int st[1005][1005];
bool cmp(Node a,Node b){
    return a.num>b.num;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)scanf("%d",&a[i].num);
    a[1].IsR=true;
    int nx=1,ny=1;
    sort(a+1,a+1+n*m,cmp);
    for(int i=2;i<=n*m;i++){
        if(nx%2==0){
            ny--;
        }else{
            ny++;
        }
        if(ny==0){
            ny=1;
            nx++;
        }else if(ny>n){
            ny=n;
            nx++;
        }
        if(a[i].IsR){
            printf("%d %d",nx,ny);
            break;
        }
    }
    return 0;
}
