/*

15:26
不是还考字符串，我是真的服，还是多串问题， 

15:43
出题人专门卡了根号做法，我真的服

15:49
我理解了，第一次和最后一次不等的地方是定了的，也就是说这个长度也是定下来了的 
按照（最后一次不同-第一次不同）大小排序 

16:00
那么只有在这种情况下才有可能是对的，然后相等位置是定了的，这下喷不了了 

16:17
这个还有点难写，感觉要调一会儿 

16:39
这个也太难写了吧，要思考一下策略了 
先写个暴力，看一下t4再说？ 
不行，相信自己码力，快写T3 

18:04
nm啊假了,这下真完蛋了,快改 

18:26
完蛋了今天没做t4,应该开t4的 
这下心态爆炸了 

*/
#include<bits/stdc++.h>
using namespace std;
namespace Sasuke{
//	#define int long long
	#define ull unsigned long long
//	#define ll long long
	#define maxm 500005
	#define maxv 5000005
	#define maxn 1005
	#define mod 1000000007
	#define inf 0x3f3f3f3f
	#define base 1145141
	#define msk cerr
	int cas,T,n,N,m,ans;
	int A[maxm];
	ull bs[maxv];
	struct node{
		string s,t;
		int id,n,l,r,len;
		ull h1,h2;
		vector<ull>h[2];
		ull Get(int op,int l,int r){return h[op][r]-h[op][l-1]*bs[r-l+1];}
	}a[maxm],b[maxm];
	bool cmp(node x,node y){return x.h1==y.h1?x.h2<y.h2:x.h1<y.h1;} 
//	bool cmp1(node x,node y){return x.len<y.len;} 
	void init(node &a){
		a.n=a.s.size();a.s=' '+a.s;a.t=' '+a.t;
		int l=a.n+1,r=0;
		for(int i=1;i<=a.n;i++)if(a.s[i]!=a.t[i])l=min(l,i),r=max(r,i);
		if(!r)return;
//		msk<<a.s<<" "<<a.t<<" "<<l<<" "<<r<<"\n";
		a.l=l;a.r=r;a.len=r-l+1;
		ull h1=0,h2=0;
		for(int i=l;i<=r;i++)h1=h1*base+a.s[i];
		for(int i=l;i<=r;i++)h2=h2*base+a.t[i];
		a.h1=h1;a.h2=h2;
		h1=0,h2=0;
		a.h[0].push_back(0);a.h[1].push_back(0);
		for(int i=1;i<=a.n;i++)h1=h1*base+a.s[i],a.h[0].push_back(h1);//,msk<<h1<<" ";msk<<"\n";
		for(int i=1;i<=a.n;i++)h2=h2*base+a.t[i],a.h[1].push_back(h2);//,msk<<h2<<" ";msk<<"\n";
	}
	struct srh{
		int l,r,id;
		friend bool operator <(srh x,srh y){return x.l==y.l?x.id<y.id:x.l<y.l;} 
	}; 
	struct fenwick{
		int t[maxm];
		void add(int x,int y){for(;x<=N;x+=x&-x)t[x]+=y;}
		int ask(int x){int sum=0;for(;x;x-=x&-x)sum+=t[x];return sum;}
	}t;
	vector<srh>f[30][30];
	int li[maxm];
	void Sol(int l1,int r1,int l2,int r2){//两个区间的哈希值完全相同 
		N=0;
		for(int i=0;i<26;i++)for(int j=0;j<26;j++)f[i][j].clear();
		for(int i=l1;i<=r1;i++)for(int j=l2;j<=r2;j++){
			int n1=a[i].l,n2=a[i].n-a[i].r+1;
//			msk<<a[i].l<<" "<<a[i].r<<" "<<b[j].l<<" "<<b[j].r<<"\n"; 
			if(b[j].l-n1+1<1||b[j].r+n2-1>b[j].n)continue;
			int L=b[j].l-a[i].l+1;
//			   msk<<"?:"<<L<<"\n";
//			msk<<b[j].Get(0,L,L+a[i].n-1)<<" "<<a[i].Get(0,1,a[i].n)<<"\n";
//			msk<<b[j].Get(1,L,L+a[i].n-1)<<" "<<a[i].Get(1,1,a[i].n)<<"\n";
			if(b[j].Get(0,L,L+a[i].n-1)!=a[i].Get(0,1,a[i].n)||
			   b[j].Get(1,L,L+a[i].n-1)!=a[i].Get(1,1,a[i].n))continue;
			   A[b[j].id]++;
		} 
	}
	signed main(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		bs[0]=1;
		for(int i=1;i<maxv;i++)bs[i]=bs[i-1]*base;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i].s>>a[i].t;
			init(a[i]);
		}
		for(int i=1;i<=m;i++){
			cin>>b[i].s>>b[i].t;
			b[i].id=i;init(b[i]);
		}
		sort(a+1,a+n+1,cmp);sort(b+1,b+m+1,cmp);
//		for(int i=1;i<=n;i++)msk<<a[i].s<<" "<<a[i].t<<" "<<a[i].h1<<" "<<a[i].h2<<"\n"; 
//		msk<<"==========\n";
//		for(int i=1;i<=m;i++)msk<<b[i].s<<" "<<b[i].t<<" "<<b[i].h1<<" "<<b[i].h2<<"\n"; 
		for(int l1=1,l2=1;l1<=n;l1++){
			int r1=l1;
			while(r1+1<=n&&a[r1+1].h1==a[l1].h1&&a[r1+1].h2==a[l1].h2)r1++;
//			msk<<l1<<" "<<r1<<" "<<l2<<"\n";
			while(l2<=m&&b[l2].h1<a[l1].h1)l2++;//让b的h1等于a的h1
			if(b[l2].h1!=a[l1].h1){l1=r1;continue;}// b的h1不等于a的h1，没有询问 
			while(l2<=m&&b[l2].h2<a[l1].h2)l2++;//让b的h2等于a的h2 
			if(b[l2].h2!=a[l1].h2){l1=r1;continue;}// b的h2不等于a的h2，没有询问
			int r2=l2; 
			while(r2+1<=m&&b[r2+1].h1==a[l1].h1&&b[r2+1].h2==a[l1].h2)r2++;
//			msk<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"\n";
			//相等哈希值，可以算答案了[l1,r1][l2,r2] 
			Sol(l1,r1,l2,r2);l1=r1;l2=r2;
		}
		for(int i=1;i<=m;i++)cout<<A[i]<<"\n";
		return 0;
	}
} 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Sasuke::main();
	return 0; 
} 
