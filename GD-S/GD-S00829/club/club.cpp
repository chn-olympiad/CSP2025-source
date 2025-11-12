#include<bits/stdc++.h>
using namespace std;
const int N=1<<21;
char in[N],*p1=in,*p2=in,out[N],*p3=out;
inline char gc(){
	return p1==p2&&(p2=(p1=in)+fread(in,1,N,stdin),p1==p2)?EOF:*p1++;
}
template<typename T>
inline void read(T &x){
	x=0;
	char c=gc();
	while(!isdigit(c)) c=gc();
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=gc();
	}
}
long long t,n,ans,a[100010][5],c1,c2,c3,dp[5][5][5][100010];
long long dfs(int x,int y,int z,int d) {
	if(d>n) return c1+c2+c3;
	if(dp[x][y][z][d]!=0) return dp[x][y][z][d];
	long long sum=0;
	if(x+1<=n/2) {
		c1+=a[d][1];
		sum=max(sum,dfs(x+1,y,z,d+1));
		c1-=a[d][1];
	}
	if(y+1<=n/2) {
		c2+=a[d][2];
		sum=max(sum,dfs(x,y+1,z,d+1));
		c2-=a[d][2];
	}
	if(z+1<=n/2) {
		c3+=a[d][3];
		sum=max(sum,dfs(x,y,z+1,d+1));
		c3-=a[d][3];
	}
	return dp[x][y][z][d]=sum;
}
void dfs1(int x,int y,int z,int d) {
	if(d>n){
		ans=max(ans,c1+c2+c3);
		return;
	}
	if(x+1<=n/2) {
		c1+=a[d][1];
		dfs1(x+1,y,z,d+1);
		c1-=a[d][1];
	}
	if(y+1<=n/2) {
		c2+=a[d][2];
		dfs1(x,y+1,z,d+1);
		c2-=a[d][2];
	}
	if(z+1<=n/2) {
		c3+=a[d][3];
		dfs1(x,y,z+1,d+1);
		c3-=a[d][3];
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--) {
		memset(dp,0,sizeof dp);
		read(n); 
		for(int i=1; i<=n; i++) {
			read(a[i][1]);
			read(a[i][2]);
			read(a[i][3]);
		}
		c1=c2=c3=0;
		if(n<=13){
			dfs1(0,0,0,1);
			cout<<ans<<endl;
			ans=0;
		}
		else{
			int x=0,y=0,z=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
					x++;
					c1+=a[i][1];
				}
				else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
					y++;
					c2+=a[i][2];
				}
				else{
					z++;
					c3+=a[i][3];
				}
			}
			if(x<=n/2&&y<=n/2&&z<=n/2) cout<<c1+c2+c3<<endl;
			else cout<<dfs(0,0,0,1)<<endl;
		}
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
