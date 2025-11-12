#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int f,id;
};
bool cmp(node a,node b){
    return a.f>b.f;
}
node a[120];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].f;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int pm;
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1) pm=i;
    }
    int x=1,y=1;
    for(int i=1;i<pm;i++){
        if(x%2==1){
            if(y!=n) y++;
            else x++;
        }else{
            if(y!=1) y--;
            else x++;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
