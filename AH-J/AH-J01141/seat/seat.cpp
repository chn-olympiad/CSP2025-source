#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int x,id;
};
node s[1000];
bool cmp(node u,node v){
    return u.x>v.x;
}
int dx[10]={1,-1};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i].x;
        s[i].id=i;
    }
    sort(s+1,s+n*m+1,cmp);
    int x=0,y=1,d=0;
    for(int i=1;i<=n*m;i++){
        int tx=x+dx[d];
        if(tx<1||tx>n){
            d=(d+1)%2;
            y+=1;
        }else{
            x=tx;
        }
        if(s[i].id==1){
            cout<<y<<" "<<x;
            break;
        }
    }
    return 0;
}
