#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll a[105],n,m,xx,yy,w;
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m>>a[1];
  w=a[1];
  cout<<w<<" ";
  for(int i=2;i<=n*m;i++){cin>>a[i];}
  sort(a+1,a+n*m+1);
  for(int i=n*m;i>=1;i--){cout<<a[i]<<" ";}
  for(int i=1;i<=n*m;i++){
    if(a[n*m-i]==w){
	  i++;
	  cout<<i<<" ";
	  if(i%n!=0){
		xx=i/n+1;
		if(n%2==0){yy=i-i/n*n+1;}
		else{yy=i-i/n*n;}
	  }
	  else{
		xx=i/n;
		if(xx%2==1){yy=n;}
		else{yy=1;}
	  }
	  
	  break;
	}
  }
  cout<<xx<<" "<<yy;
  return 0;
}
// 2 2 99 100 98 97


