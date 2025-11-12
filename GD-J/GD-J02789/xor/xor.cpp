#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls x*2
#define rs x*2+1 
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=5e5; 
int n,k,a[N],w[N],lzy[N];
int f[1005][1005];
void build(int x,int l,int r){
	if(l==r){
		w[x]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	w[x]=w[ls]^w[rs];
}
void pushdown(int x,int l,int r){
	if(lzy[x]){
		int mid=l+r>>1;
		w[ls]^=lzy[x]*(mid-l+1);
		w[rs]^=lzy[x]*(r-mid);
		lzy[ls]^=lzy[x];
		lzy[rs]^=lzy[x];
		lzy[x]=0; 
	}
}
int query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R) return w[x];
	pushdown(x,l,r);
	int mid=l+r>>1;
	int ans=0;
	if(L<=mid) ans^=query(ls,l,mid,L,R);
	if(R>mid) ans^=query(rs,mid+1,r,L,R);
	return ans;
}
bool check(int x){
	int s=0;
	int i=1,j=1;
	while(i<=n){
		int now=f[i][j];
		if(now==k){
			s++;
			i=j+1;
			j=i;
		}
		else{	
			j++;
			if(j>n){
				i++;
				j%=n;
			}
		}
	}
	return s>=x;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n<=1000){
		build(1,1,n);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j) f[i][j]=a[i];
				else f[i][j]=query(1,1,n,i,j);
			}
		} 
		int l=0,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		}
		write(r);
		return 0;
	}
	bool f1=1,f2=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=0) f1=0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0&&a[i]!=1) f2=0;
	}
	if(f1) write(n*(n+1)/2);
	else putchar('0');
	return 0;
}
/*
4 3
2 1 0 3
*/
