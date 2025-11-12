#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5];
int flag=1;int flag1=1;
int h[100005];int y[100005];int u1[100005];int u2[100005];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--){
cin>>n;
for(int i=1;i<=n;i++){
 for(int j=1;j<=3;j++){
    cin>>a[i][j];
    if(j==2||j==3){
    if(a[i][j]!=0)
    flag=0;
 }
 if(j==3){
    if(a[i][j]!=0)
    flag1=0;
 }
 }
}
if(n==2){
int cnt1=-1;int v1=0,u1=0,v2=0,u2=0;
    for(int i=1;i<=n;i++){
    for(int j=1;j<=3;j++){
    for(int j1=1;j1<=3;j1++)
    if(j!=j1){
    cnt1=max(cnt1,a[2][j]+a[1][j1]);
    }
    }
    }
    cout<<cnt1;
    return 0;
}
if(flag==1){
long long ans=0;
for(int i=1;i<=n;i++)
    h[i]=a[i][1];
for(int i=n;i>n/2;i--){
    ans+=h[i];
}
cout<<ans;
}
if(flag1=1){
long long ans=0;int a1=0,a2=0;
for(int i=1;i<=n;i++){
    h[i]=max(a[i][1],a[i][2]);
    if(h[i]==a[i][1])u1[++a1]=i;
    else u2[++a2]=i;
    ans+=h[i];
}
if(a1>n/2){
    for(int i=1;i<=a1;i++)
    y[i]=a[i][2];
    sort(y+1,y+n);
}
cout<<ans;continue;
}
long long ans=0;
for(int i=1;i<=n;i++){
for(int j=1;j<=3;j++){
            if(a[i][1]>a[i][j]){
    a[i][1]=max(a[i][j],a[i][j]);
        }
    }
    }
    for(int i=1;i<=n;i++){
    ans+=a[i][1];
    }
    cout<<ans;
}
return 0;
}
