#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,M=998244353;
int n,a[N],f[N][N],h,g,r;
int ksm(int a,int b){
	int s=1;
	while(b){
		if(b&1)s=s*a%M;
		b>>=1;a=a*a%M;
	}
	return s;
}
void dfs1(int x,int s){
	if(s>h)r++;
	for(int i=1; i<x; i++)dfs1(i,s+a[i]);
}
int dfs2(int x,int s){
	if(f[x][s]!=-1)return f[x][s];
	int w=0;
	for(int i=1; i<x; i++){
		if(s+a[i]>h)break;
		w=(w+dfs2(i,s+a[i])+1)%M;
	}
	f[x][s]=w;
	return w;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;memset(f,-1,sizeof(f));
	for(int i=1; i<=n; i++)cin>>a[i],g+=a[i];
	sort(a+1,a+n+1);
	if(g==n){
		cout<<(ksm(2,n)-1-n-n*(n-1)/2+M)%M;
		return 0;
	}
	if(n<=20){
		for(int i=1; i<=n; i++){
			h=a[i];
			dfs1(i,0);
		}
		cout<<r;
		return 0;
	}
	for(int i=1; i<=n; i++){
		h=a[i];
		r=(r+dfs2(i,0)+1)%M;
	}
	cout<<(ksm(2,n)-1-r+M)%M;
	return 0;
} 
