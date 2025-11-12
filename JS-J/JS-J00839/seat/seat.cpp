#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m;
  cin>>n>>m;
  int N=n*m,cnt=0;
  int a[N+1];
  for(int i=1;i<=N;i++){
    cin>>a[i];
  }
  cnt=a[1];
  sort(a+1,a+N);
  for(int j=1;j<=N;j++){
    if(a[j]==cnt){
        cnt=N-j;
        break;
    }
  }
  int ans1=1,ans2=1;
  while(cnt>=n){
    cnt-=n;
    ans1++;
  }


  if(cnt==0){
    if(ans1%2==1){
    ans2=1;
  }
  else{
    ans2=n;
  }
    cout<<ans1-1<<" "<<ans2;
    return 0;
  }


  else{
    if(ans1%2==1){
    ans2=cnt;
  }
  else{
    ans2=n-cnt+1;
  }
  cout<<ans1<<" "<<ans2;
  return 0;
  }
}


