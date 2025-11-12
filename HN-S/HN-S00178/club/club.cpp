#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int buf[1<<10];
inline void print(int x,char ch=' '){
	if(x<0) putchar('-'),x=-x;
	int tot=0;
	do{
		buf[++tot]=x%10;
		x/=10;
	}while(x);
	for(int i=tot;i;i--)
		putchar(buf[i]+'0');
	putchar(ch);
}
const int MAXN=1e5+5,inf=1e18;
int T;
int n,a[MAXN][3];
vector<int> e[3];
int temp[MAXN],tot;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		
		for(int i=0;i<3;i++) e[i].clear();
		int ans=0;

		for(int i=1;i<=n;i++){
			int mx=-inf;
			for(int j=0;j<3;j++){
				a[i][j]=read();
				mx=max(mx,a[i][j]);
			}
			if(a[i][0]==mx) e[0].push_back(i);
			else if(a[i][1]==mx) e[1].push_back(i);
			else e[2].push_back(i);
			ans+=mx;
		}

		if(max({e[0].size(),e[1].size(),e[2].size()})<=n/2){
			print(ans,'\n');
			continue;
		}

		int id;
		if(e[0].size()>n/2) id=0;
		else if(e[1].size()>n/2) id=1;
		else id=2;
		
		tot=0;
		for(auto x:e[id]){
			int v;
			if(id==0) 
				v=a[x][0]-max(a[x][1],a[x][2]);
			else if(id==1) 
				v=a[x][1]-max(a[x][0],a[x][2]);
			else
				v=a[x][2]-max(a[x][0],a[x][1]);
			temp[++tot]=-v; 
		}
		sort(temp+1,temp+tot+1,cmp);
		int num=e[id].size()-n/2;
		for(int i=1;i<=num;i++) ans+=temp[i];

		print(ans,'\n');
	}
	return 0;
}