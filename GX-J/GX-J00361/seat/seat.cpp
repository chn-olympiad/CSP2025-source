#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int d;
    bool q=false;
}a[105];
bool cmp(node x,node y){
    return x.d>y.d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].d;
    }
    a[1].q=true;
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=m;i++){
        for(int k=1;k<=n;k++){
            if(i%2==1){
                if(a[n*(i-1)+k].q){
                    cout<<i<<" "<<k<<endl;
                    return 0;
                }
            }
            else{
                if(a[n*(i-1)+k].q){
                    cout<<i<<" "<<n-k+1<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
