#include<bits/stdc++.h>
using namespace std;
int n,m,need;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int l=n*m;
    for(int i=1;i<=l;i++){
        cin>>a[i];
    }
    need=a[1];
    sort(a+1,a+1+l,cmp);
    int nx=1,ny=0,pos=1;//up1 down2
    for(int i=1;i<=l;i++){
        if(pos==1){
            if(ny+1<=n) ny++;
            else nx++,pos=2;
        }
        else{
            if(ny-1>=1) ny--;
            else nx++,pos=1;
        }
        if(a[i]==need){
            cout<<nx<<" "<<ny;
            return 0;
        }
    }
    return 0;
}
