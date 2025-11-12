#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int t,n,ans,num[3];
struct member{
	int x,y,z,t;
	int g;
	int id;
}a[maxn];
bool cmp36(member cty,member why){
	if(cty.x-cty.y!=why.x-why.y)return cty.x-cty.y>why.x-why.y;
	return cty.z-cty.y<why.z-why.y;
}
bool cmp24(member cty,member why){
	if(cty.z-cty.t!=why.z-why.t)return cty.z-cty.t>why.z-why.t;
	return cty.y-cty.x<why.y-why.x;
}
bool cmp99(member cty,member why){
	return cty.y-cty.x>why.y-why.x;
}
void solve(){
	cin>>n;
	ans = num[1] = num[2] = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].id = i;
	}
//	cout<<n;
	sort(a+1,a+n+1,cmp36);
	for(int i = 1;i<=n;i++){
//		cout<<a[i].id<<" in";
		if(i*2<=n){
			a[i].t = a[i].x,ans+=a[i].x;
			a[i].g = 1;
//			cout<<1;
		}
		else{
			a[i].t = a[i].y,ans+=a[i].y;
			a[i].g = 2;
//			cout<<2;
		}
//		cout<<'\n';
	}
	sort(a+1,a+n+1,cmp24);
	for(int i = 1;i*2<=n;i++)if(a[i].z-a[i].t>0){
		ans = ans - a[i].t + a[i].z;
		num[a[i].g]++;
		a[i].g = 3;
	}
	sort(a+1,a+n+1,cmp99);
	for(int i = 1;i<=n&&num[2];i++)if(a[i].y-a[i].x>0&&a[i].g==1){
		a[i].g = 2;
		ans = ans-a[i].x+a[i].y;
		num[2]--;
	}
	sort(a+1,a+n+1,cmp36);
	for(int i = 1;i<=n&&num[1];i++)if(a[i].x-a[i].y>0&&a[i].g==2){
		a[i].g = 1;
		ans = ans-a[i].y+a[i].x;
		num[1]--;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
} 
/*
1
10
4 21 29
6 23 25
3 13 24
5 17 30
14 18 11
8 22 28
12 20 27
15 1 9
2 7 16
26 10 19
*/
