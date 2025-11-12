#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
string s;
int arr[501];
int temp[501];
int vis[501];
bool A=true;
long long answer=0;
const int N=998244353;


void dfs(int rt){
  if(rt==n+1){
    int cc=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
      if(cc>=temp[i]){
        cc++;
        continue;
      }
      if(s[i-1]=='1'){
        cnt++;
      }
      else if(s[i-1]=='0'){
        cc++;
      }
    }
    if(cnt>=m)answer++;
    return;
  } 
  for(int i=1;i<=n;i++){
    if(vis[i]==0){
      temp[rt]=arr[i];
      vis[i]=1;
      dfs(rt+1);
      vis[i]=0;
      temp[rt]=0;
    }
  }
}

int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  cin>>n>>m;
  cin>>s;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<s.length();i++){
    if(s[i]!='1')A=false;
  }
  if(n<=10){
    dfs(1);
    cout<<answer%N<<"\n";
    return 0;
  }
  else if(A){
    answer=1;
    for(int i=1;i<=n;i++){
      answer=(answer*i)%N;
    }
    cout<<answer<<"\n";
    return 0;
  }
  return 0;
}
