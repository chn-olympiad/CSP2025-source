#include<bits/stdc++.h>
using namespace std;
int n,m;
struct S{
    int sum,id;
}a[10100];
bool cmp(S a,S b){
    return a.sum>b.sum;
}
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].sum;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    int xx=1,yy=0;

    for(int i=1;i<=m*n;i++){
        if(xx%2==1&&yy<n){
            yy++;
        }
        else if(xx%2==1&&yy==n){
            xx++;
        }
        else if(xx%2==0&&yy>1){
            yy--;
        }
        else if(xx%2==0&&yy==1){
            xx++;
        }
        if(a[i].id==1){
            cout<<xx<<" "<<yy;
            return 0;
        }
    }
    /*
    for(int i=1;i<=100;i++) cout<<i<<' ';
        */
    return 0;
}
