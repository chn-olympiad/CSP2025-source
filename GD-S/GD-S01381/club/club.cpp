#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int p[205][205][205],rest[10],ans;
struct node{
	int x,y,z;
}a[100005];
bool cmp(node l,node r){
	return l.x>r.x;
}
bool cmp2(node l,node r){
	return l.x-l.y>r.x-r.y;
}
void solve(){
	int n;cin>>n;
	ans = 0;
	memset(p,0,sizeof(p));
	int ff = 1,fff = 1;
	for(int i =1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].z||a[i].y)ff = 0;
		if(a[i].z)fff = 0;
	}
	if(ff){
		sort(a+1,a+n+1,cmp);
		for(int i =1;i<=n/2;i++)ans += a[i].x;
		cout<<ans<<"\n";return; 
	}
	if(fff){
		sort(a+1,a+n+1,cmp2);
		for(int i =1;i<=n/2;i++)ans += a[i].x; 
		for(int i =n/2+1;i<=n;i++)ans += a[i].y; 
		cout<<ans<<"\n";return;
	}
	for(int l =1;l<=n;l++){
		for(int i =n/2;i>=0;i--){
			for(int j =n/2;j>=0;j--){
				for(int k =n/2;k>=0;k--){
					if(i+j+k>n)continue;
					if(i)p[i][j][k] = max(p[i][j][k],p[i-1][j][k]+a[l].x);
					if(j)p[i][j][k] = max(p[i][j][k],p[i][j-1][k]+a[l].y);
					if(k)p[i][j][k] = max(p[i][j][k],p[i][j][k-1]+a[l].z);
					ans = max(ans,p[i][j][k]);
				}
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		solve();
	} 
	return 0;
} 
