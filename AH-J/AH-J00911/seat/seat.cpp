#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x=1,y=0;
struct node{
    int w,id;
}a[105];
bool cmp(node x,node y){
    return x.w>y.w;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].w;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(x%2==1){
            y++;
            if(y>m){
                x++;
                y=m;
            }
        }else{
            y--;
            if(y<1){
                x++;
                y=1;
            }
        }
        if(a[i].id==1){
            cout<<x<<" "<<y;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
