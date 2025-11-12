#include<bits/stdc++.h>
using namespace std;
struct xy{
    int x,y;
};
int n,m;
xy a[120];
bool cmp(xy q,xy p){
    return p.y<q.y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        int t;
        cin>>t;
        a[i].x=i;
        a[i].y=t;
    }
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i].x==0){
            int ax=i/n+1;
            int ay=i%n;
            if(ax%2){
                cout<<ax<<" "<<ay+1;
            }
            else{
                cout<<ax<<" "<<n-ay;
            }
            return  0;
        }
    }
    return 0;
}
