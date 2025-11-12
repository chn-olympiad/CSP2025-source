#include <bits/stdc++.h>//100
using namespace std;
const int N = 105;
int n,m;
struct stu{
  int def;//ตรทึ 
  bool xR;//ะกR 
}a[N];
bool cmp(stu x,stu y){
  return x.def>y.def;
}
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  for (int i=1; i<=n*m;i++){
  	cin>>a[i].def;
  }
  a[1].xR=1;
  sort(a+1,a+n*m+1,cmp);
  for (int i=1; i<=n;i++){
	for (int j=1; j<=m;j++){
	  if (a[(i-1)*n+j].xR){
	  	if (i%2==1){
	  	  cout<<i<<" "<<j;
	  	  exit(0);
		}
		else{
		  cout<<i<<" "<<m-j+1;
		  exit(0);
		}
	  }
	}
  } 
  return 0;
}
