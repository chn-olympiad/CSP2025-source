#include<iostream>
#include<cstring>
#define int long long
using namespace std;
const int N = 1000;
const int MOD = 998244353;
int n,m;
string d;
int nx[N];
int lowbit(int x){
  return x&-x;
}
int sel[N];
int cnt = 0;
void dp(int day,int choose){
  if(day==-1){
    int a=0,b=0;
    for(int i = 0;i<n;i++){
      if(d[i]-'0'==0||a>=nx[sel[i]]){
	a++;
      }
      else{
	b++;
      }
    }
    if(b>=m){cnt++;}
  }
  for(int i = 0;i<n;i++){
    if(choose&(1<<i)){
      continue;
    }
    choose|= 1<<i;
    sel[day] = i;
    dp(day-1,choose);
    choose-=1<<i;
  }
}
signed main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);  
  cin>>n>>m;
  cin>>d;
  bool sub_a=true;
  for(auto i:d){
    if(i-'0'==0){
      sub_a=false;
      break;
    }
  }
  int zero = 0;
  for(int i = 0;i<n;i++){
    cin>>nx[i];
    if(nx[i] ==0)zero++;
  }
  if(sub_a){
    /*
    int numb = 1;
    if(n-zero<m){cout<<0<<endl;return 0;}
    for(int i = 2;i<n;i++){
      numb*=i;
      numb%=MOD;
    }
    cout<<numb<<endl;
    return 0;
    */
  }

  dp(n-1,0);
  cout<<cnt<<endl;
  return 0;
}
