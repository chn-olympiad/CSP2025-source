#include<bits/stdc++.h>
using namespace std;
int n,m,xx=1,yy=1;
bool b=0;
struct node{
    int x,y;
};
node a[105];
bool cmp(node a,node b){
    return a.x>b.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].x;
        a[i].y=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].y==1){
            cout<<xx<<' '<<yy;
            break;
        }
        if(yy==m&&b){
            xx++;
            b=0;
        }else if(yy==1&&b){
            xx++;
            b=0;
        }else if(xx%2==1){
            yy++;
        if(yy==m){
            b=1;
        }
        }else{
            yy--;
            if(yy==1){
                b=1;
            }
        }
    }
    return 0;
}
