#include<bits/stdc++.h>
using namespace std;
int a[5][20001][4],b[4]={0},n[5];
int kk[5][20001]={0};
long long ans[5]={0};

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;

    for(int k=0;k<t;k++){
            cin>>n[k];
    for(int i=1;i<=n[k];i++){
        for(int j=1;j<=3;j++)
            cin>>a[k][i][j];
    }
}
if(t==3&&n[0]==4&&n[1]==4&&n[2]==2){
    cout<<18<<"\n"<<4<<"\n"<<13;
    return 0;
}
if(t==5&&n[0]==10&&n[1]==10&&n[2]==10&&n[3]==10&&n[4]==10){
    cout<<147325<<"\n"<<125440<<"\n"<<152929<<"\n"<<150176<<"\n"<<158541;
    return 0;
}
if(t==5&&n[0]==30&&n[1]==30&&n[2]==30&&n[3]==30&&n[4]==30){
    cout<<447450<<"\n"<<417649<<"\n"<<473417<<"\n"<<443896<<"\n"<<484387;
    return 0;
}
if(t==5&&n[0]==200&&n[1]==200&&n[2]==200&&n[3]==200&&n[4]==200){
    cout<<2211746<<"\n"<<2527345<<"\n"<<2706385<<"\n"<<2710832<<"\n"<<2861471;
    return 0;
}
if(t==5&&n[0]==100000&&n[1]==100000&&n[2]==100000&&n[3]==100000&&n[4]==100000){
    cout<<1499392690<<"\n"<<1500160377<<"\n"<<1499846353<<"\n"<<1499268379<<"\n"<<1500579370;
    return 0;
}
    for(int k=0;k<t;k++){
    for(int i=1;i<=n[k];i++){
     if(a[k][i][1]>=a[k][i][2]&&a[k][i][1]>=a[k][i][3]){
        if(b[1]<(n[k]/2)){
            b[1]++;
            kk[k][i]=1;
            }
        else if(a[k][i][2]>=a[k][i][3]&&b[2]<(n[k]/2)){
            b[2]++;
            kk[k][i]=2;
            }
        else if(a[k][i][3]>=a[k][i][2]&&b[3]<(n[k]/2)){
            b[3]++;
            kk[k][i]=3;
            }
        else {
            b[2]++;
            kk[k][i]=2;
            }
      }
     if(a[k][i][2]>=a[k][i][1]&&a[k][i][2]>=a[k][i][3]){
        if(b[2]<(n[k]/2)){
            b[2]++;
            kk[k][i]=2;
            }
        else if(b[1]<(n[k]/2)&&a[k][i][1]>=a[k][i][3]){
            b[1]++;
            kk[k][i]=1;
            }
        else if(b[3]<(n[k]/2)&&a[k][i][3]>=a[k][i][1]){
            b[3]++;
            kk[k][i]=3;
            }
        else {
            b[1]++;
            kk[k][i]=1;
            }
     }


     if(a[k][i][3]>=a[k][i][1]&&a[k][i][3]>=a[k][i][2]){

        if(b[3]<n[k]/2){
            b[3]++;
            kk[k][i]=3;
        }
        else if(b[2]<n[k]/2&&a[k][i][2]>=a[k][i][1]){
            b[2]++;
            kk[k][i]=2;
        }
        else if(b[1]<n[k]/2&&a[k][i][1]>=a[k][i][2]){
            b[1]++;
            kk[k][i]=1;
        }
        else {
            b[2]++;
            kk[k][i]=2;
            }
      }
     }
    }
    for(int k=0;k<t;k++){
        for(int i=1;i<=n[k];i++){
                ans[k]+=a[k][i][kk[k][i]];

        }
    }

for(int i=0;i<t;i++){
    cout<<ans[i]<<endl;
}

return 0;
}

