#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    bool is;
};
node stu[105];
bool cmp(node a,node b){
    return a.val>b.val;
}
int n,m,id,r,c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>stu[i].val;
    }
    stu[1].is=1;
    sort(stu+1,stu+m*n+1,cmp);
    for(int i=1;i<=m*n;i++){
        if(stu[i].is==1){
            id=i;
        }
    }
    if(id%n==0){
        c=id/n;
    }
    else{
        c=id/n+1;
    }
    if(c%2==1){
        r=id-(c-1)*n;
    }
    else{
        r=n-id+(c-1)*n+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
