#include<bits/stdc++.h>
using namespace std;
int n,m,b[101],xr,l,h,a[11][11],z;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
            cin>>b[i];
    xr=b[1];h=l=1;
    sort(b+1,b+n*m+1,cmp);
    while(b[++z]!=xr){
        a[h][l]=b[z];
        if(l%2==1) h++;
        else h--;
        if(h==n+1){l++;h=n;}
        if(h==0){l++;h=1;}
    }
    cout<<l<<' '<<h<<endl;
    return 0;
    }
