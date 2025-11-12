#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100;
struct node{
	int x,y,z;
}a[N];
bool cmp1(node a,node b){return a.x>b.x;}
bool cmp2(node a,node b){return a.y>b.y;}
bool cmp3(node a,node b){return a.z>b.z;}
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	int ans=0,x=0,y=0,z=0;
	sort(a+1,a+n+1,cmp1);
	for(int i=1,cnt=0;i<=n;i++)
		if(cnt<=n/2){
			if(a[i].x>a[i].y&&a[i].x>a[i].z)cnt++;
			x+=max(max(a[i].x,a[i].y),a[i].z);
		}else x+=(max(a[i].y,a[i].z));
	sort(a+1,a+1+n,cmp2);
	for(int i=1,cnt=0;i<=n;i++)
		if(cnt<=n/2){
			if(a[i].y>a[i].x&&a[i].y>a[i].z)cnt++;
			y+=max(max(a[i].x,a[i].y),a[i].z);
		}else y+=max(a[i].x,a[i].z);
	sort(a+1,a+1+n,cmp3);
	for(int i=1,cnt=0;i<=n;i++)
		if(cnt<=n/2){
			if(a[i].z>a[i].x&&a[i].z>a[i].y)cnt++;
			z+=max(max(a[i].x,a[i].y),a[i].z);
		}else z+=max(a[i].x,a[i].y);
	ans+=max(max(x,y),z);
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
