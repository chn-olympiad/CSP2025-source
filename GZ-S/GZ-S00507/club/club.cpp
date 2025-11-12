//GZ-S00507 都匀市第二中学 黄泰灵
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][4];
//bool ba[100005][4];
//int d[4][100005];
//int ans[4];
/*void cfin(){
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            d[1][i]=a[i][1]+a[i-1][1];
            d[2][i]=a[i][2]+a[i-1][2];
            d[3][i]=a[i][3]+a[i-1][3];
    }

}
void cfans(int x,int y,int j){
    int mid;
    if(x+1>=y){
        ba[x][j]=1;
    }
    else{
        if((x+y)%2==0)mid=(x+y)/2+1;
        else mid=(x+y)/2;
        if(a[j][mid]<a[j][y]){
            cfans(mid,y);
            }
        if(a[j][mid]>a[j][y]){
            cfans(x,mid);
            }
    }
}*/
bool com(int a,int b){
    return a>b;
}
void A(){
    cin>>n;
    int b[n+5];
    for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            b[i]=a[i][1];
    }
    sort(b,b+n,com);
    int ans;
    for(int i=1;i<=(n/2);i++){
        ans=b[i]+ans;
    }
    cout<<ans+1;
}



int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        //cfin();
        //for(int i=1;i<=3;i++){
            //cfans(0,n,i);
        //}
        //for(int i=1;i<=n;i++){
            //if()
        //}
        A();
    }

    return 0;
}
