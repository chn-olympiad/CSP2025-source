#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,c,c2,c3,k,ans;
struct o{
	int x,y,z,use;
}a[1000005];
int more;
int check(o x){
	if(more==1)return x.x-max(x.y,x.z);
	if(more==2)return x.y-max(x.x,x.z);
	return x.z-max(x.x,x.y);
}
bool cmp(o x,o y){
	if(more==1)return x.x-max(x.y,x.z)<y.x-max(y.y,y.z);
	if(more==2)return x.y-max(x.x,x.z)<y.y-max(y.x,y.z);
	return x.z-max(x.x,x.y)<y.z-max(y.x,y.y);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=more=c=c2=c3=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)c++,a[i].use=1;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)c2++,a[i].use=2;
			else c3++,a[i].use=3;
			ans+=max(a[i].x,max(a[i].y,a[i].z));
		}
		if(c>n/2)more=1,k=c;
		if(c2>n/2)more=2,k=c2;
		if(c3>n/2)more=3,k=c3;
		if(more==0){
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n&&k>n/2;i++){
			if(a[i].use==more){
				ans-=check(a[i]);
				k--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
