#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
bool cmp(int x,int y){
    return x>y;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=0;i<n*m;i++){
        cin>>a[i];
   }
   int t=a[0],f;
   sort(a,a+n*m,cmp);
   for(int i=0;i<n*m;i++){
        if(a[i]==t){
            f=i+1;
            break;
        }
   }
   int x=f/n,y=f%n;
   if(y!=0){
        if(x%2==0)cout<<x+1<<' '<<y;
        else cout<<x+1<<' '<<n-y+1;
   }else{
       cout<<x<<' '<<n;
   }
   return 0;
}
