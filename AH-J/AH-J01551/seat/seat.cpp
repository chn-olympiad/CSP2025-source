#include<bits/stdc++.h>
using namespace std;
struct node{
    int r;
    bool f=0;
};
node a[225];
bool cmp(node a,node b){
    return a.r>b.r;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    a[1].f=1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].r;
    }
    sort(a+1,a+1+n*m,cmp);
    /*for(int i=1;i<=n*m;i++){
        cout<<a[i].r<<" ";
    }*/
    //cout<<"\n";
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i&1){
            for(int j=1;j<=m;j++){
                cnt++;
                //cout<<cnt<<"\n";
                if(a[cnt].f){
                    cout<<i<<" "<<j;
                    exit(0);
                }
            }
        }
        else{
            for(int j=m;j>=1;j--){
                cnt++;
                if(a[cnt].f){
                    cout<<i<<" "<<j;
                    exit(0);
                }
            }
        }
    }
    return 0;
}
