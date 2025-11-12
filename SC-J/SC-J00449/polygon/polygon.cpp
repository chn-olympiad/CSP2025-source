#include<bits/stdc++.h>
using namespace std;
long long const mod=998244353;
int const N=5e3+1;
bool used[N];
int a[N],r[N];
long long ans=0;
int n;
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
void dfs(int pos,int k){//当前选到第pos根
	if(pos==k+1){
		int sum=0,mx=0;
		for(int i=1;i<=k;i++){
			sum+=a[r[i]];
			mx=max(mx,a[r[i]]);
		}
		ans=(ans+(sum>(mx<<1)))%mod;
		return;
	}
	for(int i=r[pos-1];i<=n;i++){
		if(!used[i]){
			r[pos]=i;
			used[i]=1;
			dfs(pos+1,k);
			used[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	r[0]=1;
	for(int i=3;i<=n;i++){
		dfs(1,i);
	}
	print(ans);
	return 0;
}