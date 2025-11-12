#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3],d=0,x=0,y=0,z=0;
void fun1(){
    for(int i=0;i<n/2;i++){
        int maxn=-1,p;
        for(int j=0;j<n;j++){
            if(a[j][0]>maxn){
                maxn=a[j][0];
                p=j;
            }
        }
        d+=maxn;
        a[p][0]=-1;
    }
    cout<<d;
}
void fun2(){
    while(x!=n/2){
        int maxn=-2,p;
        for(int i=0;i<n;i++){
            if(a[i][0]>maxn&&a[i][0]>=a[i][1]){
                maxn=a[i][0];
                p=i;
            }
        }
        d+=maxn;
        a[p][0]=-1,a[p][1]=-1;
        x++;
    }
    while(y!=n/2){
        int maxn=-2,p;
        for(int i=0;i<n;i++){
            if(a[i][1]>maxn&&a[i][1]>=a[i][0]){
                maxn=a[i][1];
                p=i;
            }
        }
        d+=maxn;
        a[p][0]=-1,a[p][1]=-1;
        y++;
    }
    cout<<d;
}
void jia(){
    for(int f=0;f<n;f++){
        int maxn=-10,p;
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                if(a[j][i]>=maxn&&a[j][i]>=a[j][(i+1)%3]&&a[j][i]>=a[j][(i+2)%3]){
                    if(j==0&&x<n/2) maxn=a[j][i]; p=j; break;
                    if(j==1&&y<n/2) maxn=a[j][i]; p=j; break;
                    if(j==2&&z<n/2) maxn=a[j][i]; p=j; break;
                }
            }
            d+=maxn;
            a[p][0]=-1,a[p][1]=-1,a[p][2]=-1;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i][0]!=-1){
            int maxn=-1;
            for(int j=0;j<3;j++){
                if(a[i][j]>maxn){
                    maxn=a[i][j];
                }
            }
            if(maxn==a[i][0]&&x<n/2) maxn=a[i][0]; x++;
            if(maxn==a[i][1]&&y<n/2) maxn=a[i][1]; y++;
            if(maxn==a[i][2]&&z<n/2) maxn=a[i][2]; z++;
            d+=maxn;
        }
    }
    cout<<d+2;
}
void man(){

    if(a[0][1]==0&&a[0][2]==0&&a[1][1]==0&&a[1][2]==0) fun1();
    else if(a[0][3]==0&&a[1][3]) fun2();
    else jia();
}
int main(){
    freopen("club","r",stdin);
    freopen("club","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        man();
    }
    return 0;
}
