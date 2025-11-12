#include<bits/stdc++.h>
using namespace std;
int a[1005];
int cp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
  int n,m;
  cin>>n>>m;
  int cnt=0;
  cin>>a[1];
  cnt=a[1];
  for(int i=2;i<=n*m;i++){
	cin>>a[i];
  }
  sort(a+1,a+1+n*m,cp);
  int sum=0;
  for(int i=1;i<=n*m;i++){
	  if(a[i]==cnt){
		  sum=i;
		  break;
	  }
  }
  int x=sum/n;
  int y=sum%n;
  if(y==0) {
	  y=n;
  }else{
	  x++;
  }
  if(x%2==1){
	  cout<<x<<' '<<y;
  }else{
	  cout<<x<<' '<<n+1-y;
  }
  return 0;
}
