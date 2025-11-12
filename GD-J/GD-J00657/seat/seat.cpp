#include<bits/stdc++.h>
// #define int long long
using namespace std;

int n,m;
int a[101];

signed main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>n>>m;

  for(int i=1;i<=n*m;i++){
    cin>>a[i];
  } 

  int x=a[1];

  sort(a+1,a+n*m+1);
  reverse(a+1,a+n*m+1);

  // int pos=lower_bound(a+1,a+n*m+1,x)-a;
  int pos=0;
  for(int i=1;i<=n*m;i++) if(a[i]==x) pos=i;

  int s,t,num;

  s=pos/n,num=pos%n;

  if(num){
    if(s&1) t=n-num+1;
    else t=num;
    s++;
  }
  else{
    if(s&1) t=n;
    else t=1;
  }

  cout<<s<<' '<<t<<'\n';

}