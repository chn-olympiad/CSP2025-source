#include<bits/stdc++.h>
using namespace std;
int a[110];
int m,n,x;
int ans(int x){
while(x-m>0)x-=m;
return x;
}
int main(){
/*freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);*/
cin>>n>>m;
for(int i=1;i<=n*m;i++)cin>>a[i];
int r=a[1];
for(int i=1;i<=n*m;i++){
    if(a[i]==r){
        x=i;break;
    }
}
int ansa=x/m;

if(ansa%2!=0)ansa++;
if(ansa==0)ansa++;
cout<<ansa<<' ';
if(x%2==1){
    cout<<ans(x);
}else cout<<m-ans(x)+1<<endl;
return 0;
}
