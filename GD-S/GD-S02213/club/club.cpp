#include<bits/stdc++.h>
using namespace std;
namespace IO{
	void read(int &x){
		short f=1;x=0;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
		x*=f;
		return;
	}
	void out_(int x){
		if(x>9) out_(x/10);
		putchar(x%10+'0');
		return;
	}
	void out(int x){
		if(x<0) putchar('-'),x=-x;
		out_(x);putchar(' ');
		return;
	}
}using namespace IO;
char st;
const int N=2e5+5;
int T,n,a[N][3],f[205][205][205],id[N],bz[N];
int top;
struct node{
	int val,x,y;
}d[3*N];
char ed;
void file(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return;
}
bool sub(){
	for(int i=1;i<=n;i++) 
		if(a[i][2]) return false;
	return true;
}
bool cmp(int x,int y){
	return a[x][0]-a[x][1]>a[y][0]-a[y][1];
}
bool cmp1(node x,node y){
	return x.val>y.val;
}
void solve(){
	if(n<=200){
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				for(int k=0;j+k<=i;k++){
					int l=i-j-k;
					if(j-1>=0)
					f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][0]);
					if(k-1>=0)
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][1]);
					if(l-1>=0)
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][2]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(n-i-j<=n/2){
					ans=max(ans,f[n][i][j]);
				}
			}
		}
		out(ans),putchar('\n');
		return;		
	}
	else if(sub()){
		for(int i=1;i<=n;i++) id[i]=i;
		sort(id+1,id+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++)
			if(i<=n/2) ans+=a[id[i]][0];
			else ans+=a[id[i]][1];
		out(ans),putchar('\n');
	}
	else{
		top=0;
		for(int i=1;i<=n;i++){
			d[++top]=(node){a[i][0],i,0};
			d[++top]=(node){a[i][1],i,1};
			d[++top]=(node){a[i][2],i,2};
		}
		sort(d+1,d+top+1,cmp1);
		for(int i=1;i<=n;i++) bz[i]=0;
		int ans=0;
		for(int i=1;i<=top;i++){
			if(bz[d[i].x]) continue;
			bz[d[i].x]=1;
			ans+=d[i].val;
		}
		out(ans),putchar('\n');
	}
	return;
}
int main(){
	file();
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;i++){
			read(a[i][0]),read(a[i][1]),read(a[i][2]);
		}
		solve();
	} 
	return 0;
}  
