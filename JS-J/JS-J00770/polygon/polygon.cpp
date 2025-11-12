#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int n,a[1000006],cnt=0;
void dfs(long long sum,int mn,int step,int sl,int xz){
    if(step==n)return;
    if(mn*2<sum&&sl>2&&xz==1){

          //  cout<<sum<<" "<<mn<<" "<<step<<" "<<sl<<"\n";


            cnt++;
    }
    dfs(sum+a[step+1],mn,step+1,sl+1,1);
    dfs(sum,mn,step+1,sl,0);
}
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
     sort(a,a+n,cmp);
     for(int i=0;i<n-2;i++){

     dfs(a[i],a[i],i,1,1);
     }

cout<<cnt%998244353;
    return 0;
}
