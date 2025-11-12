#include<bits/stdc++.h>
using namespace std;

const int N=3e3,p=998244353;

int in(){
	int t=1,k=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	return t*k;
}

void out(int x){
	if(x<0)x=-x,putchar('-');
	if(x<10)return putchar(x+'0'),void(0);
	out(x/10);putchar(x%10+'0');
}

int a[N],vis[N],n,vis2[N];
int ans=0;
void dfs(int maxx,int sum,int dep){
	if(dep>=n)return; 
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		//vis[i]=1;
		//maxx=max(maxx,a[i]);
		if(maxx*2<sum&&dep>=3){
			ans++;
		}
		vis[i]=1;
		dfs(max(maxx,a[i]),sum+a[i],dep+1);	
		vis[i]=0;		
		vis[i]=1;
		dfs(a[i],sum,dep);
		vis[i]=0;
	}
}

int yi=0;

int kkk(int x,int k){
	int ans=1;
	while(k){
		if(k&1)ans=(ans*x)%p;
		x=(x*x)%p;
		k>>=1;
	}
	return ans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	n=in();
	int maxx=0;
	for(int i=1;i<=n;i++){
		a[i]=in();
		maxx=max(maxx,a[i]);
		if(a[i]==1)yi++;
	}
	if(n<=3){
		if(n==3){
			
			if(maxx*2<a[1]+a[2]+a[3])out(1);
			else out(0);
			return 0;
		}else if(n<3){
			out(0);
			return 0;
		}
	}
	if(yi>=n/2){
		int daan=kkk(2,n);
		daan=(daan-1-n-n*(n-1)/2);
		daan=(daan+p)%p;
		out(daan);
		return 0;
	}
	//dfs(0,0,1);
	out(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
2 2
99 100 97 98

5
1 2 3 4 5
*/