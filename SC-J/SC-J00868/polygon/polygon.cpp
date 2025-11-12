#include<bits/stdc++.h>
using namespace std;
int ans,n,a[5005],v[5005];
void d(int cnt,int s,int mx,int m){
	if(cnt==0&&s>2*mx) {ans++;return;}
	for(int i=m;i<=n;i++){
		if(v[i]==1)continue;
		s+=a[i],v[i]=1;
		int nx=max(mx,a[i]);
		d(cnt-1,s,nx,i);
		s-=a[i],v[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)d(i,0,0,1);
	cout<<ans;
	return 0;
}