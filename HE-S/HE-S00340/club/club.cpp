#include<bits/stdc++.h>
#define int long long
using namespace std;;
int t;
int n;
const int N=2e5+1010;
struct node{
	int x,y,z;
	bool f;
}a[N];
int xx[N],yy[N],zz[N],xxx,yyy,zzz;
int ans;
bool cmp1(node f,node g){
	return f.x>g.x;
}
bool cmp2(node f,node g){
	return f.y>g.y;
}
bool cmp3(node f,node g){
	return f.z>g.z;
}
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin>>n;
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].f=0;
		if(a[i].y==0){
			sum1++;
		}
		if(a[i].z==0){
			sum2++;
		}
	}
	if(sum1==n&&sum2==n){
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].x;
		}
		cout<<ans<<"\n";
	}
	else if(sum2==n){
		for(int i=1;i<=n;i++){
			if(a[i].x>a[i].y){
				xx[++xxx]=i;
			}
			else{
				yy[++yyy]=i;
			}
		}
		if(xxx>n/2){
			sort(xx+1,xx+1+xxx,cmp);
			for(xxx;xxx>=n/2;xxx--){
				yy[++yyy]=xx[xxx];
				xx[xxx]=0;
			}
		}
		if(yyy>n/2){
			sort(yy+1,yy+1+yyy,cmp);
			for(yyy;yyy>=n/2;yyy--){
				xx[++xxx]=yy[yyy];
				yy[yyy]=0;
			}
		}
		for(int i=1;i<=xxx;i++){
			ans+=a[xx[xxx]].x;
		}
		for(int i=1;i<=yyy;i++){
			ans+=a[yy[yyy]].y;
		}
		cout<<ans<<"\n";
	}
	else if(n==2){
		ans=max(a[1].x+a[2].y,ans);
		ans=max(a[1].x+a[2].z,ans);
		ans=max(a[1].y+a[2].x,ans);
		ans=max(a[1].y+a[2].z,ans);
		ans=max(a[1].z+a[2].x,ans);
		ans=max(a[1].z+a[2].y,ans);
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		solve();
	}
	
	
	
	
	
	
	
	
	return 0;
}
