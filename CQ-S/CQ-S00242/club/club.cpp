#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define debug(x) cerr<<"debug: "<<#x<<" = "<<x<<endl
using namespace std;
namespace code{
	inline ll read(){
		int f=1;ll x=0;char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-f;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+(ch-'0');
			ch=getchar();
		}
		return f*x;
	}
	struct node{
		int x,y,z,d;
	}p[100005];
	int n;
	ll num1,num2,num3,sum;
	inline void doit(int i){
		int x=read(),y=read(),z=read();
		int mx=max({x,y,z});
		p[i]={x,y,z,mx};
		int t=0;
		if(x>=y&&y>=z) t=y;
		if(x<=y&&y<=z) t=y;
		if(x>=z&&z>=y) t=z;
		if(x<=z&&z<=y) t=z;
		if(y>=x&&x>=z) t=x;
		if(y<=x&&x<=z) t=x;
		p[i].d-=t;
		sum+=mx;
		if(mx==x) num1++;
		else if(mx==y) num2++;
		else num3++;
	}
	int cnt,a[100005];
	void solve(){
		sum=0,num1=0,num2=0,num3=0,cnt=0;
		n=read();
		for(int i=1;i<=n;i++) doit(i);
		int mx=max({num1,num2,num3});
		if(mx<=n/2){
			cout<<sum<<"\n";
			return ;
		}
		if(mx==num1){for(int i=1;i<=n;i++) if(max({p[i].x,p[i].y,p[i].z})==p[i].x) a[++cnt]=p[i].d;}
		else if(mx==num2){for(int i=1;i<=n;i++) if(max({p[i].x,p[i].y,p[i].z})==p[i].y) a[++cnt]=p[i].d;}
		else{for(int i=1;i<=n;i++) if(max({p[i].x,p[i].y,p[i].z})==p[i].z) a[++cnt]=p[i].d;}
		sort(a+1,a+cnt+1);
//debug(sum);debug(mx);
//debug(cnt);for(int i=1;i<=cnt;i++) debug(a[i]);
		for(int i=1;i<=mx-n/2;i++) sum-=a[i];
		cout<<sum<<"\n";
	}
	signed main(){
		int T;
		T=read();
		while(T--) solve();
//while(1);
		return 0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return code::main();
}
/*
0.2S/1S
2M/512M
*/
