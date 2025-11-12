#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
//#define int long long
//#define int __int128
//#define int unsigned int
//#define mod
using namespace std;
void fio(string s,int i){
	freopen((s+(i?to_string(i):"")+".in").c_str(),"r",stdin);
	freopen((s+(i?to_string(i):"")+".out").c_str(),"w",stdout);
}
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}return ret*f;
}
inline void write(int x,int op=0){
	if(x<0){
		putchar('-');
		x=-x;
	}
	stack<char>qwq;
	while(!qwq.empty())qwq.pop();
	while(x>9){
		qwq.push(x%10+'0');
		x/=10;
	}
	qwq.push(x+'0');
	while(!qwq.empty())putchar(qwq.top()),qwq.pop();
	if(op>0)putchar('\n');
	if(op<0)putchar(' ');
}
const int N=1e5+5,M=205;
int T;
int n,m,ans;
bool vis[N];
struct node{
	int x,y,z,id;
}a[N];
int f[M][M>>1][M>>1];
vector<node>b1;
bool cmp1(node x,node y){
	return x.x==y.x?(x.y==y.y?x.z<y.z:x.y<y.y):x.x<y.x;
}
vector<node>b2;
bool cmp2(node x,node y){
	return x.y==y.y?(x.z==y.z?x.x<y.x:x.z<y.z):x.y<y.y;
}
vector<node>b3;
bool cmp3(node x,node y){
	return x.z==y.z?(x.x==y.x?x.y<y.y:x.x<y.x):x.z<y.z;
}
signed main(){
	fio("club");
	T=read();
	while(T--){
		n=read();
		m=n>>1;
		b1.clear();
		b2.clear();
		b3.clear();
		for(int i=1;i<=n;i++){
			a[i]={read(),read(),read(),i};
			b1.push_back(a[i]);
			b2.push_back(a[i]);
			b3.push_back(a[i]);
		}
		if(n<=200){
			ans=0;
			memset(f,0,sizeof f);
			for(int i=1;i<=n;i++){
				for(int j=min(m,i-1);j>=0;j--){
					for(int k=min(m,i-j);k>=max(i-j-m,0);k--){
						if(j==m){
							f[i][j][k+1]=max(f[i][j][k+1],f[i-1][j][k]+a[i].y);
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
						}else if(k==m){
							f[i][j+1][k]=max(f[i][j+1][k],f[i-1][j][k]+a[i].x);
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
						}else{
							f[i][j+1][k]=max(f[i][j+1][k],f[i-1][j][k]+a[i].x);
							f[i][j][k+1]=max(f[i][j][k+1],f[i-1][j][k]+a[i].y);
							if(i-j-k<m)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
							else f[i][j][k]=0;
						}
					}
				}
			}
			for(int i=0;i<=m;i++){
				for(int j=max(m-i,0);j<=m;j++){
					ans=max(ans,f[n][i][j]);
				}
			}write(ans,1);
		}else{
			memset(vis,0,sizeof vis);
			ans=0;
			sort(b1.begin(),b1.end(),cmp1);
			sort(b2.begin(),b2.end(),cmp2);
			sort(b3.begin(),b3.end(),cmp3);
			int c1=0,c2=0,c3=0;
			while(c1+c2+c3<n){
				while(!b1.empty()&&vis[b1.back().id])b1.pop_back();
				while(!b2.empty()&&vis[b2.back().id])b2.pop_back();
				while(!b3.empty()&&vis[b3.back().id])b3.pop_back();
				if(c1==m){
					if(b2.back().y>b3.back().z){
						c2++;
						ans+=b2.back().y;
						vis[b2.back().id]=1; 
						b2.pop_back(); 
					}else{
						c3++;
						ans+=b3.back().z;
						vis[b3.back().id]=1; 
						b3.pop_back(); 
					}
				}else if(c2==m){
					if(b1.back().x>b3.back().z){
						c1++;
						ans+=b1.back().x;
						vis[b1.back().id]=1; 
						b1.pop_back(); 
					}else{
						c3++;
						ans+=b3.back().z;
						vis[b3.back().id]=1; 
						b3.pop_back(); 
					}
				}else if(c3==m){
					if(b1.back().x>b2.back().y){
						c1++;
						ans+=b1.back().x;
						vis[b1.back().id]=1; 
						b1.pop_back(); 
					}else{
						c2++;
						ans+=b2.back().y;
						vis[b2.back().id]=1; 
						b2.pop_back(); 
					}
				}else{
					if(b1.back().x>=b2.back().y&&b1.back().x>=b3.back().z){
						c1++;
						ans+=b1.back().x;
						vis[b1.back().id]=1; 
						b1.pop_back(); 
					}else if(b2.back().y>=b3.back().z){
						c2++;
						ans+=b2.back().y;
						vis[b2.back().id]=1; 
						b2.pop_back(); 
					}else{
						c3++;
						ans+=b3.back().z;
						vis[b3.back().id]=1; 
						b3.pop_back(); 
					}
				}
			}write(ans,1);
		}
	}
	return 0;
}

