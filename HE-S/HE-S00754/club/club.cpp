#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+5;
int n,t;
struct stu{
  int x,y,z;
}a[N];
bool tsA;
ll ans;
bool cmpA(stu x,stu y){
  return x.x>y.x;
}
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  while (t--){
  	ans=0,tsA=1;
  	cin>>n;
  	for (int i=1; i<=n;i++){
	  cin>>a[i].x>>a[i].y>>a[i].z;
	  if (a[i].y!=0&&a[i].z!=0) tsA=0;
	}
	if (tsA){
	  sort(a+1,a+n+1,cmpA);
	  for (int i=1; i<=n/2;i++){
	  	ans+=a[i].x;
	  }
	  cout<<ans<<'\n';
	  continue;
    }
	cout<<max(max(
	max(a[1].x+a[2].y,a[1].x+a[2].z),
	max(a[1].y+a[2].x,a[1].y+a[2].z)),
	max(a[1].z+a[2].x,a[1].z+a[2].y)
	)<<'\n';
  }
  return 0;
}
