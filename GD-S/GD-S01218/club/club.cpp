#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
struct aa{
	int a,b,c;
}l[N];
int n,t,ans=0;
bool vis[N];
void dfs(int dep,int x,int y,int z,int d){
	if(dep==n+1){
		ans=max(ans,d);
	}
	if(x>0){
		dfs(dep+1,x-1,y,z,d+l[dep].a);
	}
	if(y>0){
		dfs(dep+1,x,y-1,z,d+l[dep].b);
	}
	if(z>0){
		dfs(dep+1,x,y,z-1,d+l[dep].c);
	}
}
bool cmp1(aa x,aa y){
	return x.a>y.a;
}
bool cmp2(aa x,aa y){
	return x.b-x.a>y.b-y.a; 
}
bool cmp3(aa x,aa y)
{
	return x.a-x.b>y.a-y.b;
}
bool cmp4(aa x,aa y){
	return x.c-x.a>y.c-y.a;
}
bool cmp5(aa x,aa y){
	return x.c-x.b>y.c-y.b; 
}
bool cmp6(aa x,aa y){
	return x.b-x.c>y.b-y.c; 
}
bool cmp7(aa x,aa y){
	return x.a-x.c>y.a-y.c; 
}
void solve(){
	bool f1=true,f2=true;
	ans=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> l[i].a >> l[i].b >> l[i].c;
		if(l[i].b!=0){
			f1=false;
		}
		if(l[i].c!=0){
			f2=f1=false;
		}
	}
	if(n<=10){
		dfs(1,n/2,n/2,n/2,0);
		cout << ans << "\n";
		return;
	}
	if(f1){
		int ans=0;
		sort(l+1,l+n+1,cmp1);
		for(int i=1;i<=n/2;i++){
			ans+=l[i].a;
		}
		cout << ans << "\n";
		return;
	}
	if(f2){
		int ans1=0;
		for(int i=1;i<=n;i++){
			ans1+=l[i].a;
		}
		sort(l+1,l+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			ans1-=l[i].a;
			ans1+=l[i].b;
		}

		cout << ans1 << "\n"; 
		return;
	}
	int ans1,ans2,ans3,ans=0;
	ans1=ans2=ans3=0;
	for(int i=1;i<=n;i++){
		ans1+=l[i].a;
		ans2+=l[i].b;
		ans3+=l[i].c;
	}
	//1 a
	memset(vis,0,sizeof(vis));
//	yan=as1;
	sort(l+1,l+n+1,cmp2);
	for(int i=1;i<=n/2;i++){
		ans1-=l[i].a;
		ans1+=l[i].b;
		vis[i]=1;
	}
	ans=max(ans,ans1);
	sort(l+1,l+1+n,cmp4);
	for(int i=1;i<=n/2;i++){
		if(vis[i]){
			ans1-=l[i].b;
			ans1+=l[i].a;
		}
		ans1-=l[i].a;
		ans1+=l[i].c;
	}
	ans=max(ans,ans1);
	//2 b
	memset(vis,0,sizeof(vis));
	sort(l+1,l+n+1,cmp3);
	for(int i=1;i<=n/2;i++){
		ans2-=l[i].b;
		ans2+=l[i].a;
		vis[i]=1;
	}
	ans=max(ans,ans2);
	sort(l+1,l+1+n,cmp5);
	for(int i=1;i<=n/2;i++){
		if(vis[i]){
			ans2-=l[i].a;
			ans2+=l[i].b;
		}
		ans2-=l[i].b;
		ans2+=l[i].c;
	}
	ans=max(ans,ans2);
	// 3 c
	memset(vis,0,sizeof(vis));
	sort(l+1,l+n+1,cmp6);
	for(int i=1;i<=n/2;i++){
		ans3-=l[i].c;
		ans3+=l[i].b;
		vis[i]=1;
	}
	ans=max(ans,ans3);
	sort(l+1,l+1+n,cmp7);
	for(int i=1;i<=n/2;i++){
		if(vis[i]){
			ans3-=l[i].b;
			ans3+=l[i].c;
		}
		ans3-=l[i].c;
		ans3+=l[i].a;
	}
	ans=max(ans,ans3);	
	cout << ans<< "\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
