#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
  return x>y;
}

int main(){

  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);

  int n,m;
  cin>>n>>m;
  int a[n*m]={0};
  for(int i=0;i<n*m;i++){
    cin>>a[i];
  }

  int r=a[0];
  int id;
  sort(a,a+n*m,cmp);
  for(int i=0;i<n*m;i++){
    if(a[i]==r)id=i;
  }
  int k[n][m];

  int rn,rm;
  int mc=0;
  int ans=0;
  for(int i=0;i<n;i++){
    if((i+1)%2==0){
      for(int j=m-1;j>=0;j--){
        if(ans==id){
          rn=i;
          rm=j;
          break;
        }
        mc+=1;
      }
    }else{
      for(int j=0;j<m;j++){
        if(ans==id){
          rn=i;
          rm=j;
          break;
        }
        mc+=1;
      }
    }
    if(mc==m){
      i++;
      mc=0;
    }else{
      i--;
    }
    ans+=1;
  }
  cout<<rn+1<<" "<<rm+1;

  return 0;
}
