#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int s,id;
}a[21000];
bool cmp(node x,node y){
    return x.s>y.s;
}
int ans_x=1,ans_y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].s;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            cout<<ans_x<<" "<<ans_y;
            break;
        }else{
            if(ans_x%2==1){
                ans_y++;
                if(ans_y>m){
                    ans_x++;
                    ans_y=m;
                }
            }else{
                ans_y--;
                if(ans_y==0){
                    ans_x++;
                    ans_y=1;
                }
            }
        }
    }
    return 0;
}