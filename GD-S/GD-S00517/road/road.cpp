#include<bits/stdc++.h>
#define fo(i,x,y) for(register int i=(x);i<=(y);++i)
#define co const
using namespace std;
co int N=1001;
struct ed{
	int x,y,z;
}a[499501];
int b[11][N],c[N][N],d[N],f[N],e[N][N],n,w;
long long minn=LONG_LONG_MAX;
void input(int &a){
	static char c=getchar();
	a=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		a=(a<<3)+(a<<1)+(c^48);
		c=getchar();
	}
}
void print(co long long a){
	if(a>9)
		print(a/10);
	putchar(a%10|48);
}
bool cmp(co ed &x,co ed &y){
	return x.z<y.z;
}
int fd(co int x){
	if(f[x]!=x)
		f[x]=fd(f[x]);
	return f[x];
}
void dg(co int x){
	if(x>w){
		int t=0,z=0;
		long long s=0;
		fo(i,1,n){
			f[i]=i;
			fo(j,1,n)
				e[i][j]=c[i][j];
		}
		fo(i,1,d[0]){
			s+=b[d[i]][0];
			fo(j,1,n-1)
				fo(k,j+1,n)
					e[j][k]=e[k][j]=min(e[j][k],b[d[i]][j]+b[d[i]][k]);
		}
		fo(i,1,n-1)
			fo(j,i+1,n){
				a[++z].x=i;
				a[z].y=j;
				a[z].z=e[i][j];
			}
		sort(a+1,a+1+z,cmp);
		fo(i,1,z){
			const int u=fd(a[i].x),v=fd(a[i].y);
			if(u!=v){
				f[u]=v;
				s+=a[i].z;
				if(s>=minn||++t==n-1)
					break;
			}
		}
		minn=min(minn,s);
		return;
	}
	d[++d[0]]=x;
	dg(x+1);
	--d[0];
	dg(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,x,y,z;
	input(n);
	input(m);
	input(w);
	fo(i,1,n-1)
		fo(j,i+1,n)
			c[i][j]=c[j][i]=INT_MAX;
	while(m--){
		input(x);
		input(y);
		input(z);
		c[x][y]=c[y][x]=min(c[x][y],z);
	}
	fo(i,1,w)
		fo(j,0,n)
			input(b[i][j]);
	dg(1);
	print(minn);
	return 0;
}
