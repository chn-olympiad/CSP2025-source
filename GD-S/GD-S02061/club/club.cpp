//ccf orz
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return f*x;
} 
const int N=1e5+10;
int t,n,k,ans;
struct node{
	int a1,a2,a3;
}a[N];
inline void dfs(int x1,int x2,int x3,int w){
	if(x1+x2+x3==n){
		ans=max(ans,w);
		return;
	}
	if(x1<k) dfs(x1+1,x2,x3,w+a[x1+x2+x3+1].a1);
	if(x2<k) dfs(x1,x2+1,x3,w+a[x1+x2+x3+1].a2);
	if(x3<k) dfs(x1,x2,x3+1,w+a[x1+x2+x3+1].a3);
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i].a1=read();
			a[i].a2=read();
			a[i].a3=read();
		}
		k=n/2;
		dfs(0,0,0,0);
		cout<<ans<<"\n"; 
	}
	return 0;
}
