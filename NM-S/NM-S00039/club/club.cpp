#include<bits/stdc++.h>
using namespace std;
int a[20001][3];
bool b[20001][3];
int t,n,maxs=0,dy[3]={0,1,2};
int da1[3]={1,0,0},da2[3]={0,1,0},da3[3]={0,0,1};
void d(int x,int y,long long nows,int a1,int a2,int a3){
    b[x][y]=true;
    //nows+=a[x][y];
    if(x==n){
        //nows+=a[x][y];
        if(nows>maxs){
            maxs=nows;
        }
        nows=0;
    }
    for(int i=0;i<=2;i++){
        if(a1+da1[(y+dy[i])%3]<=n/2&&a2+da2[(y+dy[i])%3]<=n/2&&a3+da3[(y+dy[i])%3]<=n/2&&x<=n){
            d(x+1,(y+dy[i])%3,nows+=a[x][y],a1+da1[(y+dy[i])%3],a2+da2[(y+dy[i])%3],a3+da3[(y+dy[i])%3]);
        }
    }
    nows=nows-a[x][y];
    b[x][y]=false;
    //cout<<nows<<" ";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j][0]>>a[j][1]>>a[j][2];
            b[j][0]=b[j][1]=b[j][2]=false;
        }
        for(int j=0;j<=2;j++){
            d(1,j,0,0,0,0);
            for(int z=1;z<=n;z++){
                b[z][0]=false;
                b[z][2]=false;
                b[z][1]=false;
            }
        }
        cout<<maxs<<endl;
        maxs=0;
    }
    return 0;
}
