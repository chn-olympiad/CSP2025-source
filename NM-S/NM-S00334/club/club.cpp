#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N],n,t,idx,y,h,b,c;
int main(){
    freopen("club.cpp","r",stdin);
    freopen("club.cpp","w",stdout);
    cin>>t;
    for(int y=1;y<=t;y++)cin>>n;
        for(int y=1;y<=t;y++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
            cin>>a[j];
            if(a[idx]<a[j])idx=j;
            if(j==1||j==2||j==3)c+=1;
           }
           h+=c;
           if(h>n/2){
            for(int j=1;j<=3;j++){
            if(j>j+1){
            if(idx==2&&a[idx+1]>a[idx-1])idx=idx+1;
            if(idx==1&&a[idx+1]>a[idx+2])idx=idx+1;
            if(idx==1&&a[idx+1]<a[idx+2])idx=idx+2;
            if(idx==3&&a[idx-1]>a[idx-2])idx=idx-1;
            if(idx==3&&a[idx-1]<a[idx-2])idx=idx-2;}
            }
           }
            b+=a[idx];
        }
        cout<<b<<endl;
}
}
