#include<bits/stdc++.h>
//#define int long long
typedef long long ll;
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+6;
struct node{
	int a[4];
} me[N];
int n,m,k,t;
int a[N],b[N],c[N];

long long ans=0;
void dfs(int k,long long sum,int r1,int r2,int r3){
	ans=max(ans,sum);
	if(k==n+1) return;
	for(int i=1;i<=4;i++){
		if(i==1&&r1!=0) dfs(k+1,sum+a[k],r1-1,r2,r3);
		if(i==2&&r2!=0) dfs(k+1,sum+b[k],r1,r2-1,r3);
		if(i==3&&r3!=0) dfs(k+1,sum+c[k],r1,r2,r3-1);
		if(i==4) dfs(k+1,sum,r1,r2,r3);
	}
}
bool cmp(int a,int b){return a>b;
}
signed main( ){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		ans=0;
		n=read();
		int flag2=1,flag3=1;
		for(int i=1;i<=n;i++){
			a[i]=read(),b[i]=read(),c[i]=read();
			if(b[i]!=0) flag2=0;
			if(c[i]!=0) flag3=0;
		}
		
		if(flag2){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
		}
		else{
			dfs(1,0,n/2,n/2,n/2);
		}
		printf("%lld",ans);
	}
	/*
	1
	4
0 1 0
0 1 0
0 2 0
0 2 0
	*/
	
	
	return 0;
} /*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/
