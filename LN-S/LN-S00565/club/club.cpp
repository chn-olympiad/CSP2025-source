#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
for(int i=1;i<=t;i++){
int n;
cin>>n;
if(n==2){
int a[3];
int b[3];
for(int i=0;i<3;i++){
cin>>a[i];
}
for(int i=0;i<3;i++){
cin>>b[i];
}
int sum[6]={a[0]+b[1],a[0]+b[2],a[1]+b[2],a[1]+b[0],a[2]+b[0],a[2]+b[1]};
int max=0;
for(int i=0;i<6;i++){
    if(sum[i]>max){
        max=sum[i];
    }
}
cout<<max;

}
}
return 0;
}
