#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=1e5+5;
struct node{
	int x,y,z;
}a[N];
bool cmp1(node a,node b){
	return (a.x-max(a.y,a.z))>(b.x-max(b.y,b.z));
}
bool cmp2(node a,node b){
	return (a.y-max(a.x,a.z))>(b.y-max(b.x,b.z));
}
bool cmp3(node a,node b){
	return (a.z-max(a.y,a.x))>(b.z-max(b.y,b.x));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int n=read(),ans=0;
		for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
		sort(a+1,a+n+1,cmp1);
		int res=0;
		for(int i=1;i<=n/2;i++) res+=a[i].x;
		for(int i=n/2+1;i<=n;i++) res+=max(a[i].y,a[i].z);
		ans=max(ans,res);
		sort(a+1,a+n+1,cmp2);
		res=0;
		for(int i=1;i<=n/2;i++) res+=a[i].y;
		for(int i=n/2+1;i<=n;i++) res+=max(a[i].x,a[i].z);
		ans=max(ans,res);
		sort(a+1,a+n+1,cmp3);
		res=0;
		for(int i=1;i<=n/2;i++) res+=a[i].z;
		for(int i=n/2+1;i<=n;i++) res+=max(a[i].x,a[i].y);
		ans=max(ans,res);
		res=0;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			int maxn=max({a[i].x,a[i].y,a[i].z});
			if(maxn==a[i].x) cnt1++;
			else if(maxn==a[i].y) cnt2++;
			else if(maxn==a[i].z) cnt3++;
			res+=maxn;
		}
		if(max({cnt1,cnt2,cnt3})*2<=n) ans=max(ans,res);
		write(ans);
		putchar('\n');
	}
	return 0;
}

