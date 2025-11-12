#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,yb,a1[N],a2[N],a3[N],cnt1,cnt2,cnt3,ans;
struct myd{
	int x,id;
}a[N][4];
struct lyy{
	int x,num;
}t[N]; 
bool cmp(myd x,myd y){
	return x.x>y.x;
}
bool cmp1(lyy x,lyy y){
	return x.x-a[x.num][1].x>y.x-a[y.num][1].x;
}
void pre(){
	cnt1=cnt2=cnt3=0;
	ans=0;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		pre();
		n=read();
		yb=n>>1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j) 
				a[i][j].x=read(),a[i][j].id=j;
			sort(a[i]+1,a[i]+1+3,cmp);
		}
		for(int i=1;i<=n;++i){
			if(a[i][1].id==1)a1[++cnt1]=i;
			else if(a[i][1].id==2)a2[++cnt2]=i;
			else if(a[i][1].id==3)a3[++cnt3]=i;
			ans+=a[i][1].x;
		}
		if(cnt1>yb||cnt2>yb||cnt3>yb){//找第二大值 
			if(cnt1>yb){
				for(int i=1;i<=cnt1;++i)//找最大的第二值进行交换 
					t[i].x=a[a1[i]][2].x,t[i].num=a1[i];
				sort(t+1,t+1+cnt1,cmp1);
				for(int i=1;i<=cnt1-yb;++i) ans+=t[i].x-a[t[i].num][1].x;
			}
			if(cnt2>yb){
				for(int i=1;i<=cnt2;++i)//找最大的第二值进行交换 
					t[i].x=a[a2[i]][2].x,t[i].num=a2[i];
				sort(t+1,t+1+cnt2,cmp1);
				for(int i=1;i<=cnt2-yb;++i) ans+=t[i].x-a[t[i].num][1].x;
			}
			if(cnt3>yb){
				for(int i=1;i<=cnt3;++i)//找最大的第二值进行交换 
					t[i].x=a[a3[i]][2].x,t[i].num=a3[i];
				sort(t+1,t+1+cnt3,cmp1);
				for(int i=1;i<=cnt3-yb;++i) ans+=t[i].x-a[t[i].num][1].x;
			}
		}
		cout<<ans<<endl;
	}
}
/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],ans,cs[4],yb;
void bfs(int cnt,int x){
	if(cnt==n){
		ans=max(ans,x);
		return ;
	}
	for(int i=1;i<=3;++i){
		if(cs[i]==yb)continue;
		cs[i]++;
		bfs(cnt+1,x+a[cnt+1][i]);
		cs[i]--;
	}
}
void pre(){
	cs[1]=cs[2]=cs[3]=0;
	ans=0;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		pre();
		n=read();
		yb=n>>1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j)a[i][j]=read();
		}
		bfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,cnt,ans,cs[4],yb;
bool vis[N];
struct myd{
	int x,id,lyy;
}a[N*3];
bool cmp(myd x,myd y){
	return x.x>y.x;
}
void pre(){
	ans=cnt=0;
	for(int i=1;i<=n;++i)vis[i]=false;
	cs[1]=cs[2]=cs[3]=0;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		pre();
		n=read();
		yb=n>>1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j) 
				a[++cnt].x=read(),a[cnt].id=j,a[cnt].lyy=i;
		}
		sort(a+1,a+1+cnt,cmp);
		for(int i=1;i<=cnt;++i){
			if(!vis[a[i].lyy]&&cs[a[i].id]<yb){
				vis[a[i].lyy]=true;
				cs[a[i].id]++;
				ans+=a[i].x;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
*/
/*
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
*/
