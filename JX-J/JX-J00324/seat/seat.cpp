#include<bits/stdc++.h>
using namespace std;
int n,m,b;int a[110];int ans=-1;
bool cmp(int x,int y){
return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;int flag=1;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
    if(a[i]!=i)flag=0;
    if(a[i]>ans)ans=a[i];
}
if(ans==a[1]){
    cout<<"1"<<" "<<"1";
    return 0;
}
if(flag==0){
int k=a[1];
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n*m;i++){
    if(a[i]==k){b=i;break;
  }
 }

int l1=b%n;
int l2=b/n;
 if(b/n==0){
    l2=1;
    cout<<l2<<" "<<l1;
    return 0;
 }
 else if(b%n==0){
    if(l2%2==0)l1=1;
    else l1=n;
    cout<<l2<<" "<<l1;
    return 0;
 }
 else if(b%n==1){
    l2=l2+1;
    if(l2%2==0)l1=n;
    else l1=1;
    cout<<l2<<" "<<l1;
    return 0;
 }
else{
l2=l2+1;
if(l2%2==0)cout<<l2<<" "<<n-l1+1;
if(l2%2!=0)cout<<l2<<" "<<l1;
return 0;
}
}
else{
    cout<<m<<" "<<n;
}
return 0;
}
