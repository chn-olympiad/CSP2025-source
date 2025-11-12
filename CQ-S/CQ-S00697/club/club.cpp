#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
const int MM=1e6;
struct node{
	ll wa,wb,wc;
}a[MM]; 
ll aa[MM];
ll bb[MM];
ll cc[MM];
ll ca,cb,ccc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=read();
	while(T--){
		ll n=read();
		ll ans=0,x,y,z;
		ll c1=0,c2=0,c3=0;
		ca=0,cb=0,ccc=0;
		for(int i=1;i<=n;i++){
			x=read(),y=read(),z=read();
			if(x>=y&&x>=z){
				c1++;
				a[i].wa=x;
				a[i].wb=max(y,z);
				a[i].wc=min(y,z);
				aa[++ca]=a[i].wa-a[i].wb;
			}else if(y>=x&&y>=z){
				c2++;
				a[i].wa=y;
				a[i].wb=max(x,z);
				a[i].wc=min(x,z);
				bb[++cb]=a[i].wa-a[i].wb;
			}else{
				c3++;
				a[i].wa=z;
				a[i].wb=max(x,y);
				a[i].wc=min(x,y);
				cc[++ccc]=a[i].wa-a[i].wb;
			}
			ans+=a[i].wa;
		} 
		ll k=n/2;
		if(c1>k||c2>k||c3>k){
			ll w=0;
			if(c1>k){
				w=c1;
				sort(aa+1,aa+1+ca);
				w-=k;
				for(int i=1;i<=w;i++)ans-=aa[i];
			}else if(c2>k){
				w=c2;
				sort(bb+1,bb+1+cb);
				w-=k;
				for(int i=1;i<=w;i++)ans-=bb[i];
			}else{
				w=c3;
				sort(cc+1,cc+1+ccc);
				w-=k;
				for(int i=1;i<=w;i++)ans-=cc[i];
			}   
		}
		write(ans);
		putchar('\n');
	}
	return 0;
} 
