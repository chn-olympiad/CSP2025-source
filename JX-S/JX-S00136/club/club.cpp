#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int t;
int n;
int cnt;
int arr[100001][4];
int temp[100001];
long long answer=0;
bool A=true;

void dfs(int rt,long long ans,int a1,int a2,int a3){
  if(a1>cnt or a2>cnt or a3>cnt){
    return;
  }
  if(rt==n){
    answer=max(answer,ans);
    return;
  }
  dfs(rt+1,ans+arr[rt+1][1],a1+1,a2,a3);
  dfs(rt+1,ans+arr[rt+1][2],a1,a2+1,a3);
  dfs(rt+1,ans+arr[rt+1][3],a1,a2,a3+1);
}

void clear(){
  for(int i=1;i<=n;i++){
    temp[i]=0;
    arr[i][1]=0;
    arr[i][2]=0;
    arr[i][3]=0;
  }
  answer=0;
}

int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    cnt=n/2;
    for(int i=1;i<=n;i++){
      cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
      if(arr[i][2]!=0 or arr[i][3]!=0)A=false;
    }
    if(n<=10){
      dfs(0,0,0,0,0);
      printf("%lld\n",answer);
    }
    else if(A){
      for(int i=1;i<=n;i++){
        temp[i]=arr[i][1];
      }
      sort(temp+1,temp+n+1,greater<int>() );
      for(int i=1;i<=cnt;i++){
        answer+=temp[i];
      }
      printf("%lld\n",answer);
    }
    clear();
  }
  return 0;
}
