#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
long long T;
long long n,ans;
struct wbx{
	long long id,c[4];
	long long v;
}a[N];
long long k[4],x;
long long f1(long long x){
	for(int i=1;i<=3;i++)
		if(x!=i) return i;
}
long long f2(long long x){
	for(int i=3;i>=1;i--)
		if(x!=i) return i; 
}
bool cmp(wbx x,wbx y){
	return x.v>y.v;
}
void solve(){
	k[0]=-1,k[1]=k[2]=k[3]=0,x=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c[1]>>a[i].c[2]>>a[i].c[3];
		k[1]+=a[i].c[1],k[2]+=a[i].c[2],k[3]+=a[i].c[3];
	}
	for(int i=1;i<=3;i++)
		if(k[x]<k[i]) x=i;
	for(int i=1;i<=n;i++)
		 a[i].v=max(a[i].c[f1(x)]-a[i].c[x],a[i].c[f2(x)]-a[i].c[x]),ans+=a[i].c[x];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n/2 || a[i].v>0;i++)
		ans+=a[i].v;
	cout<<ans<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
/*
ภÛมหกฃ 
*/ 
