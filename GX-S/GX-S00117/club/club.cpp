#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
struct club{
  int x,y,z;
}a[N];
int b[N];
int c[N];

int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>T;
  while (T--){
	int ans=0,numa=0,numb=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	for (int i=n;i>=1;i--){
		if (a[i].x>=a[i].y&&numa<n/2){numa++;ans+=a[i].x;}
		else if (a[i].x<a[i].y&&numb<n/2) {numb++;ans+=a[i].y;}
		else if (numb>=n/2&&numa<n/2) {numa++;ans+=a[i].x;}
		else if (numa>=n/2&&numb<n/2) {numb++;ans+=a[i].y;}
		else ans+=a[i].z;
	}
	cout<<ans<<endl;
  }
  return 0;
}
