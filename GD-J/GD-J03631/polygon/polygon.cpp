#include<bits/stdc++.h>
#define int long long
#define ls k<<1
#define rs k<<1|1
#define mid ((l+r)>>1)
const int N=5e3+10,mod=998244353;
using namespace std;
int n,ans;
int a[N],b[21];
struct node{
	int sum,mx;
}v[N<<2];
void pushup(int k){
	v[k].sum=v[ls].sum+v[rs].sum;
	v[k].mx=max(v[ls].mx,v[rs].mx);
}
void build(int k,int l,int r){
	if(l==r){
		v[k].sum=v[k].mx=a[l];
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(k);
}
int querysum(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R) return v[k].sum;
	if(l>R||r<L) return 0;
	return querysum(ls,l,mid,L,R)+querysum(rs,mid+1,r,L,R);
}
int querymx(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R) return v[k].mx;
	if(l>R||r<L) return 0;
	return max(querymx(ls,l,mid,L,R),querymx(rs,mid+1,r,L,R));
}
void f(int len){
	memset(b,0,sizeof(b));
	int p,q;
	if(len==3)
		for(b[1]=1;b[1]<=n-len+1;++b[1])
			for(b[2]=b[1]+1;b[2]<=n-len+2;++b[2])
				for(b[3]=b[2]+1;b[3]<=n-len+3;++b[3]){
					for(int i=1;i<=len;++i) p+=a[b[i]],q=max(q,a[b[i]]);
					if(p>2*q) ans++;
				}
	if(len==4)
		for(b[1]=1;b[1]<=n-len+1;++b[1])
			for(b[2]=b[1]+1;b[2]<=n-len+2;++b[2])
				for(b[3]=b[2]+1;b[3]<=n-len+3;++b[3])
					for(b[4]=b[3]+1;b[4]<=n-len+4;++b[4]){
						for(int i=1;i<=len;++i) p+=a[b[i]],q=max(q,a[b[i]]);
						if(p>2*q) ans++;
					}	
	if(len==5)
		for(b[1]=1;b[1]<=n-len+1;++b[1])
			for(b[2]=b[1]+1;b[2]<=n-len+2;++b[2])
				for(b[3]=b[2]+1;b[3]<=n-len+3;++b[3])
					for(b[4]=b[3]+1;b[4]<=n-len+4;++b[4])
						for(b[5]=b[4]+1;b[5]<=n-len+5;++b[5]){
							for(int i=1;i<=len;++i) p+=a[b[i]],q=max(q,a[b[i]]);
							if(p>2*q) ans++;
						}
	if(len==6)
		for(b[1]=1;b[1]<=n-len+1;++b[1])
			for(b[2]=b[1]+1;b[2]<=n-len+2;++b[2])
				for(b[3]=b[2]+1;b[3]<=n-len+3;++b[3])
					for(b[4]=b[3]+1;b[4]<=n-len+4;++b[4])
						for(b[5]=b[4]+1;b[5]<=n-len+5;++b[5])
							for(b[6]=b[5]+1;b[6]<=n-len+6;++b[6]){
								for(int i=1;i<=len;++i) p+=a[b[i]],q=max(q,a[b[i]]);
								if(p>2*q) ans++;
							}
	if(len==7)
		for(b[1]=1;b[1]<=n-len+1;++b[1])
			for(b[2]=b[1]+1;b[2]<=n-len+2;++b[2])
				for(b[3]=b[2]+1;b[3]<=n-len+3;++b[3])
					for(b[4]=b[3]+1;b[4]<=n-len+4;++b[4])
						for(b[5]=b[4]+1;b[5]<=n-len+5;++b[5])
							for(b[6]=b[5]+1;b[6]<=n-len+6;++b[6])
								for(b[7]=b[6]+1;b[7]<=n-len+7;++b[7]){
									for(int i=1;i<=len;++i) p+=a[b[i]],q=max(q,a[b[i]]);
									if(p>2*q) ans++;
								}
	if(len==8)
		for(b[1]=1;b[1]<=n-len+1;++b[1])
			for(b[2]=b[1]+1;b[2]<=n-len+2;++b[2])
				for(b[3]=b[2]+1;b[3]<=n-len+3;++b[3])
					for(b[4]=b[3]+1;b[4]<=n-len+4;++b[4])
						for(b[5]=b[4]+1;b[5]<=n-len+5;++b[5])
							for(b[6]=b[5]+1;b[6]<=n-len+6;++b[6])
								for(b[7]=b[6]+1;b[7]<=n-len+7;++b[7])
									for(b[8]=b[7]+1;b[8]<=n-len+8;++b[8]){
										for(int i=1;i<=len;++i) p+=a[b[i]],q=max(q,a[b[i]]);
										if(p>2*q) ans++;
									}
	if(len==9)
		for(b[1]=1;b[1]<=n-len+1;++b[1])
			for(b[2]=b[1]+1;b[2]<=n-len+2;++b[2])
				for(b[3]=b[2]+1;b[3]<=n-len+3;++b[3])
					for(b[4]=b[3]+1;b[4]<=n-len+4;++b[4])
						for(b[5]=b[4]+1;b[5]<=n-len+5;++b[5])
							for(b[6]=b[5]+1;b[6]<=n-len+6;++b[6])
								for(b[7]=b[6]+1;b[7]<=n-len+7;++b[7])
									for(b[8]=b[7]+1;b[8]<=n-len+8;++b[8])
										for(b[9]=b[8]+1;b[9]<=n-len+9;++b[9]){
											for(int i=1;i<=len;++i) p+=a[b[i]],q=max(q,a[b[i]]);
											if(p>2*q) ans++;
										}	
	if(len==10)
		for(b[1]=1;b[1]<=n-len+1;++b[1])
			for(b[2]=b[1]+1;b[2]<=n-len+2;++b[2])
				for(b[3]=b[2]+1;b[3]<=n-len+3;++b[3])
					for(b[4]=b[3]+1;b[4]<=n-len+4;++b[4])
						for(b[5]=b[4]+1;b[5]<=n-len+5;++b[5])
							for(b[6]=b[5]+1;b[6]<=n-len+6;++b[6])
								for(b[7]=b[6]+1;b[7]<=n-len+7;++b[7])
									for(b[8]=b[7]+1;b[8]<=n-len+8;++b[8])
										for(b[9]=b[8]+1;b[9]<=n-len+9;++b[9])
											for(b[10]=b[9]+1;b[10]<=n-len+10;++b[10]){
												for(int i=1;i<=len;++i) p+=a[b[i]],q=max(q,a[b[i]]);
												if(p>2*q) ans++;
											}
	return;																	
}
signed main(){
	freopen("polygon.in","r","std.in");
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	build(1,1,n);
	if(n<=3){
		if(n<3||querysum(1,1,n,1,n)<=2*querymx(1,1,n,1,n)) ans=0;
		else ans=1;
	}
	else if(n<=10)
		for(int len=3;len<=n;++len) f(len);
	/*
	else if(querymx(1,1,n,1,n)==1){
		int len=3;
		for(int i=1;i<=n-len+1;++i)
			for(int j=i+1;j<=n-len+2;++j)
				for(int k=j+1;k<=n-len+3;++k)
					ans++;
					ans=ans%mod;
	}
	*/
	printf("%lld",ans%mod);
	freopen("polygon.out","w","std.out");
	return 0;
}
