#include<bits/stdc++.h>
using namespace std;
struct node{
    int idx;
    int grade;
}a[105];
int n,m,loc;
bool cmp(node x,node y){
    return x.grade>y.grade;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].grade;
        a[i].idx=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].idx==1){
            loc=i;
            break;
        }
    }
    int x,y;
    y=ceil((double)loc/n);
    if(y%2){
        x=loc-(y-1)*n;
    }
    else{
        x=y*n-loc+1;
    }
    cout<<y<<" "<<x;
    return 0;
}
