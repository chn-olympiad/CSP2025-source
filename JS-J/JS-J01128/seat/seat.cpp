#include<bits/stdc++.h>
using namespace std;
struct node{
int num,pr;
}a[105];
int n,m;
bool cmp(node a,node b){
    return a.pr>b.pr;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        a[i].num=i;
        cin>>a[i].pr;
    }
    sort(a+1,a+1+n*m,cmp);
    int x=1,y=1;
    for(int i=1;i<=n*m;i++){
        if(a[i].num==1){
            cout<<y<<" "<<x;
        }
        if(y%2==1){
            x++;
            if(x>n){
                y++;
                x=n;
            }
        }else{
            x--;
            if(x<1){
                y++;
                x=1;
            }
        }
    }
    return 0;
}
