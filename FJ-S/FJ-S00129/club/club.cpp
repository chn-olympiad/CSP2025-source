#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+50;
ll T,n,cnt1,cnt2,cnt3,ans;
bool fg1=1,fg2=1;
struct node{
	ll v1,v2,v3;
}a[N];
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48),ch=getchar();}
	return x*f;
}
void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x<10){putchar(x+48);}
	else{write(x/10),putchar(x%10+48);}
	return;
}
//O(3^n)
void dfs(ll x,ll res,ll c1,ll c2,ll c3){
	if(x==n+1){
		ans=max(ans,res);
		return;
	}
	if(c1+1<=n/2)dfs(x+1,res+a[x].v1,c1+1,c2,c3);
	if(c2+1<=n/2)dfs(x+1,res+a[x].v2,c1,c2+1,c3);
	if(c3+1<=n/2)dfs(x+1,res+a[x].v3,c1,c2,c3+1);
	return;
}
bool cmp1(node x,node y){
	return x.v1>y.v1;
}
bool cmp2(node x,node y){
	return x.v1-x.v2>y.v1-y.v2;
}
bool cmp3(node x,node y){
	return x.v1-x.v3>y.v1-y.v3;
}
bool cmp4(node x,node y){
	return x.v2-x.v3>y.v2-y.v3;
}
void solve(){
	cnt1=0,cnt2=0,cnt3=0;
	ans=0;
	fg1=1,fg2=1;
	n=read();
	for(ll i=1;i<=n;i++){
		a[i].v1=read(),a[i].v2=read(),a[i].v3=read();
		if(a[i].v2!=0||a[i].v3!=0)fg1=0;
		if(a[i].v3!=0)fg2=0;
	}
	if(n<=10)dfs(1,0,0,0,0);
	else if(fg1){
		sort(a+1,a+n+1,cmp1);
		for(ll i=1;i<=n/2;i++)ans+=a[i].v1;
	}else if(fg2){
		sort(a+1,a+n+1,cmp2);
		for(ll i=1;i<=n/2;i++)ans+=a[i].v1;
		for(ll i=n/2+1;i<=n;i++)ans+=a[i].v2;
	}else{
		ll tmp=0;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++)tmp+=max(a[i].v1,a[i].v3);
		for(int i=n/2+1;i<=n;i++)tmp+=max(a[i].v2,a[i].v3);
		ans=max(ans,tmp);
		tmp=0;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n/2;i++)tmp+=max(a[i].v1,a[i].v2);
		for(int i=n/2+1;i<=n;i++)tmp+=max(a[i].v3,a[i].v2);
		ans=max(ans,tmp);
		tmp=0;
		sort(a+1,a+n+1,cmp4);
		for(int i=1;i<=n/2;i++)tmp+=max(a[i].v2,a[i].v1);
		for(int i=n/2+1;i<=n;i++)tmp+=max(a[i].v3,a[i].v1);
		ans=max(ans,tmp);
	}
	write(ans);
	putchar('\n');
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
