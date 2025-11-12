#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct mem{
	int a,b,c;
}s[100002],a[100002],b[100002],c[100002];
int sec(int x,int y,int z){
	if (x>y) swap(x,y);
	if (x>z) swap(x,z);
	if (y>z) swap(y,z);
	return y;
}
int mx(int x,int y,int z){
	return max(x,max(y,z));
}
bool cmp(mem x,mem y){
	return mx(x.a,x.b,x.c)-sec(x.a,x.b,x.c)<mx(y.a,y.b,y.c)-sec(y.a,y.b,y.c);
}
void solve(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>s[i].a>>s[i].b>>s[i].c;
	int cnt1=0,cnt2=0,cnt3=0;
	for (int i=1;i<=n;i++){
		if (max(s[i].a,max(s[i].b,s[i].c))==s[i].a) a[++cnt1]=s[i];
		else if (max(s[i].a,max(s[i].b,s[i].c))==s[i].b) b[++cnt2]=s[i];
		else c[++cnt3]=s[i];
	}
//	cout<<cnt1<<" "<<cnt2<<endl;
	int ans=0;
	if (cnt1>n/2){
		sort(a+1,a+1+cnt1,cmp);
//		for (int i=1;i<=cnt1;i++){
//			if (a[i].a-a[i].b==0) cout<<a[i].a<<" "<<a[i].b<<endl;
//			else cout<<a[i].a-a[i].b<<endl;
//		} 
		int pos=cnt1-n/2;
		for (int i=1;i<=pos;i++) ans+=sec(a[i].a,a[i].b,a[i].c);
		for (int i=pos+1;i<=cnt1;i++) ans+=a[i].a;
		for (int i=1;i<=cnt2;i++) ans+=b[i].b;
		for (int i=1;i<=cnt3;i++) ans+=c[i].c;
	}
	else if (cnt2>n/2){
		sort(b+1,b+1+cnt2,cmp);
		int pos=cnt2-n/2;
		for (int i=1;i<=pos;i++) ans+=sec(b[i].a,b[i].b,b[i].c);
		for (int i=pos+1;i<=cnt2;i++) ans+=b[i].b;
		for (int i=1;i<=cnt1;i++) ans+=a[i].a;
		for (int i=1;i<=cnt3;i++) ans+=c[i].c;
	}
	else if (cnt3>n/2){
		sort(c+1,c+1+cnt3,cmp);
		int pos=cnt3-n/2;
		for (int i=1;i<=pos;i++) ans+=sec(c[i].a,c[i].b,c[i].c);
		for (int i=pos+1;i<=cnt3;i++) ans+=c[i].c;
		for (int i=1;i<=cnt2;i++) ans+=b[i].b;
		for (int i=1;i<=cnt1;i++) ans+=a[i].a;
	}
	else{
		for (int i=1;i<=cnt1;i++) ans+=a[i].a;
		for (int i=1;i<=cnt2;i++) ans+=b[i].b;
		for (int i=1;i<=cnt3;i++) ans+=c[i].c;
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while (t--) solve();
	return 0;
}

