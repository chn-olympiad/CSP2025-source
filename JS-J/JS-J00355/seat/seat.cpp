#include<bits/stdc++.h>
using namespace std;
int dx[5]={0,0,1,0,1};
int dy[5]={0,1,0,-1,0};
int a[101111];
int n,m;
bool cmp(int x,int y){
    return x>y;
}
void work(int r){
    int x=1,y=1,dep=1,vis=0;
    for(int i=1;i<=n*m;i++){
        vis--;
        if(a[i]==r){
            cout<<x<<' '<<y;
            return ;
        }
        if(y+dy[dep]>n&&dx[dep]==0){
            dep++;
            vis=2;
        }
        if(vis==1){
            dep++;
            vis=0;
        }
        if(y+dy[dep]<1&&dx[dep]==0){
            dep++;
            vis=2;
        }
        if(dep>4)dep=1;
        x=x+dx[dep];
        y=y+dy[dep];
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)r=a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    work(r);
    return 0;
}
