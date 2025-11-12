#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=5e5+5;
int n,k;
int a[N],b[N],ans; 
int c[N],d[N],idx;
int find(int id){
	int l=1,r=idx;
	while(l<r){
		int mid=l+r>>1;
		if(d[mid]<id) l=mid+1;
		else r=mid;
	}
	return d[l];
}
void dfs(int x,int cnt){
	if(n-x+1+cnt<=ans) return ;
	if(b[x]>cnt) return ;
	if(x==n+1){
		ans=max(ans,cnt);
//		cout<<ans<<'\n';
		return ;
	}
//	cout<<x<<' '<<cnt<<'\n';
	int q=find(x);
	if(q<x) q=x+1;
	if(c[x]!=0){
		if(b[c[x]]<cnt+1){
			b[c[x]]=cnt+1;
			dfs(c[x]+1,cnt+1);
		}
		dfs(x+1,cnt);
	}else dfs(q,cnt);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=i;j<=n;j++){
			res^=a[j];
			if(res==k){
				c[i]=j;
				break;
			}
		}
		if(c[i]!=0) d[++idx]=i;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
时间复杂度最多O(nlognlogn)
问题主要出现在求异或和为k的区间 
众所周知，异或两遍会变成零(不行！！实现不了)


*/