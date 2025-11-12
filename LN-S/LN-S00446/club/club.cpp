#include<bits/stdc++.h>
using namespace std;
int arr[100001][4],vis[100001][4],num[4],dt[100001],T,n,mc=0,ma=0,mb=0,t=0,mn=0;
long long sum=0;
int maxk(int a,int b,int c){
    if((a>=b&&b>=c)||(a>=c&&c>=b))return a;
    if((b>=a&&a>=c)||(b>=c&&c>=a))return b;
    if((c>=b&&b>=a)||(c>=a&&a>=b))return c;
}int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
            sum+=maxk(arr[i][1],arr[i][2],arr[i][3]);
            if(maxk(arr[i][1],arr[i][2],arr[i][3])==arr[i][1]){
                num[1]++;
                vis[i][1]=1;
            }else if(maxk(arr[i][1],arr[i][2],arr[i][3])==arr[i][2]){
                num[2]++;
                vis[i][2]=1;
            }else if(maxk(arr[i][1],arr[i][2],arr[i][3])==arr[i][3]){
                num[3]++;
                vis[i][3]=1;
            }
        }if(num[1]<=n/2&&num[2]<=n/2&&num[3]<=n/2){
            cout<<sum;
        }else{int mn=maxk(num[1],num[2],num[3]),mc=0,ma=0,mb=0;
        if(mn==num[1]){
            mc=1;
            ma=2;mb=3;
        }else if(mn==num[2]){
            mc=2;
            ma=1;mb=3;
        }else if(mn==num[3]){
            mc=3;
            ma=1;mb=2;
        }int t=0;
        for(int i=1;i<=n;i++){
            if(vis[i][mc]==1){
                dt[t]=arr[i][mc]-maxk(arr[i][ma],arr[i][mb],-1);
                t++;
            }
        }sort(dt,dt+mn);
        for(int i=0;i<mn-n/2;i++){
            sum-=dt[i];
        }cout<<sum<<endl;}
        T--;
        sum=0;
        for(int i=0;i<num[mc];i++){
            dt[i]=0;
        }for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                vis[i][j]=0;
            }
        }num[1]=0;num[2]=0;num[3]=0;

    }fclose(stdin);
    fclose(stdout);
    return 0;
}
/*

Ren5Jie4Di4Ling5%

*/
