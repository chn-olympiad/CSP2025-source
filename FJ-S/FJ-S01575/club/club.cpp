#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int read();
int t,n,n1,a[100010][4],ans,cnt,b[5],ans2;
bool f[100010];
void dfs(int k,int sum1,int sum2,int sum3,int ans1) {
	if(k>n) {
		ans=max(ans,ans1);
		return;
	}
	if(sum1*2<n) dfs(k+1,sum1+1,sum2,sum3,ans1+a[k][1]);
	if(sum2*2<n) dfs(k+1,sum1,sum2+1,sum3,ans1+a[k][2]);
	if(sum3*2<n) dfs(k+1,sum1,sum2,sum3+1,ans1+a[k][3]);
}
void dfs1(int k,int sum1,int sum2,int sum3,int ans1) {
	if(k>n) {
		ans2=max(ans2,ans1);
		return;
	}
	if(sum1>0) dfs1(k+1,sum1-1,sum2,sum3,ans1+a[k][1]);
	if(sum2>0) dfs1(k+1,sum1,sum2-1,sum3,ans1+a[k][2]);
	if(sum3>0) dfs1(k+1,sum1,sum2,sum3-1,ans1+a[k][3]);
}
struct node{
	int a,x,y;
}a1[300010];
bool cmp(node x,node y) {
	return x.a>y.a;
}
void solve() {
	cnt=ans=0;
	for(int i=1;i<=n;i++) {
		b[i]=0;
		f[i]=false;
		for(int j=1;j<=3;j++) {
			a1[++cnt].a=a[i][j];
			a1[cnt].x=i;
			a1[cnt].y=j;
		}
	}
	sort(a1+1,a1+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) {
		if(n<=10) break;
		if(f[a1[i].x]==true || b[a1[i].y]>=n1/2) {
			continue;
		}
		ans+=a1[i].a;
		f[a1[i].x]=true;
		b[a1[i].y]++;
		n--;
	}
	int pooi=0;
	for(int i=1;i<=n1;i++) {
		if(!f[i]) {
			swap(a[++pooi],a[i]);
			if(pooi==n) {
				break;
			}
		}
	}
	dfs1(1,n1/2-b[1],n1/2-b[2],n1/2-b[3],ans);
	cout<<ans2<<endl;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t=read();
	while(t--) {
		n=n1=read(),ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) {
				a[i][j]=read();
			}
		}
		if(n>=30) {
			solve();
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}	
	return 0;
}
int read(){
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-1;}}
	while(Cr>='0' && Cr<='9') {Ca=Ca*10+Cr-48;Cr=getchar();}
	return Ca*Cf;
}