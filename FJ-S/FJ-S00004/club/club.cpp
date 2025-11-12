#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int read(){
	int x;bool f=0;char ch;
	while((ch=getchar())>'9' || ch<'0')if(ch=='-')f=1;
	x=ch-'0';
	while((ch=getchar())>='0' && ch<='9')x=(x<<3)+(x<<1)+ch-'0';
	return f?-x:x;
}
const int N=5e5+5;
int n;
struct node{
	int x,y,z;
}a[N];
map<int,map<int,map<int,int> > > dp;
long long x[N],y[N],z[N];
bool cmp(node b,node c){
	return (b.x==c.x)?((b.y==c.y)?b.z>c.z:b.y>c.y):b.x>c.x;
}
void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read(),a[i].z=read();
		x[i]=x[i-1]+a[i].x,y[i]=y[i-1]+a[i].y,z[i]=z[i-1]+a[i].z;
	}
	sort(a+1,a+n+1,cmp);
	if(y[n]==z[n] && z[n]==0){
		printf("%lld\n",x[n/2]);
		return ;
	}
	for(int i=1;i<=n;i++){
		int gyu=min(i,n/2);
		for(int j=0;j<=gyu;j++){
			for(int k=(gyu-j);k<=gyu;k++){
				int t=i-k-j;
				if(t>n/2)continue;
				if((t)<0)continue;
				int no=0;
				if(t>=1)no=max(no,dp[j][k][t-1]+a[i].z);
				if(k>=1)no=max(no,dp[j][k-1][t]+a[i].y);
				if(j>=1)no=max(no,dp[j-1][k][t]+a[i].x);
				dp[j][k][t]=no;	
			}
		}
	}
	int ans=0;
	for(int i=0;i<=(n/2);i++){
		for(int j=(n/2-i);j<=(n/2);j++){
			int k=n-(i+j);
			ans=max(ans,dp[i][j][k]);
		}
	}
	printf("%d\n",ans);
	return ;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)solve();
	return 0;
}
//:|
