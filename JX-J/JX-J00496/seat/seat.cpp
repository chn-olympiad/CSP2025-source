#include<bits/stdc++.h>
using namespace std;
int arr[105],q[12][12],n,m,k,p=1,x=1,y=1;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>arr[i];
    }
    k=arr[1];
    sort(arr+1,arr+n*m,cmp);
        while(p!=n*m){
        q[x][y]=arr[p];
        if(y%2==1&&x==n||y%2==0&&x==1) y++;
        else if(y%2==1) x++;
        else if(y%2==0) x--;
        else x+=0;
        p++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(q[i][j]==k) cout<<i<<" "<<j;
        }
    }
    return 0;
}
