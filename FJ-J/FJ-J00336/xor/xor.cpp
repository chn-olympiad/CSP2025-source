#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 500050;
ll n,k,a[N],tree[4*N],f[N],ans=0,cnt=0;
pair<int,int>qj[N];
//9:08 opening
//9:35 coding
//10:51 coded!
//预计50~60分 
void build(int dot,int l,int r){
	int m=(l+r)>>1;
	int lc=2*dot,rc=lc+1;
	if(l==r){
		tree[dot]=a[l];
		return;
	}
	build(lc,l,m);
	build(rc,m+1,r);
	tree[dot]=tree[lc]^tree[rc];
}
ll query(int dot,int l,int r,int cl,int cr){
	ll m=(l+r)>>1;
	if(cr<l||cl>r)return -1;//如果查询区间与该区间无交集 
	if(cl<=l&&cr>=r)return tree[dot];
	ll lc=2*dot,rc=lc+1;
	ll ans1=query(lc,l,m,cl,cr);
	ll ans2=query(rc,m+1,r,cl,cr);
	if(ans1==-1)return ans2;
	else if(ans2==-1)return ans1;
	else return ans1^ans2;
}
int main(){
	//a^b^c=a^(b^c)
	//也就是说，区间[l,m]的权值^区间[m+1,r]的权值等于区间[l,r]的权值 
	//看数据范围好像是O(nlogn) 
	//可能可以二分？
	//O(n) check
	//O(logn) find 
	//问题来了，结果是区间数量最大值。
	//那么难点转化为求区间[l,r]的异或和是否等于k
	//树状数组优化？log(n)查询异或区间，那么枚举首尾端点是O(n*n)的，不行
	// 况且树状数组是求前缀和的，sum(y)-sum(x-1)看看起来不行
	//考虑dp 
	//设f[i]为遍历到i时区间数量为k的值
	// 4 2
	//2 1 0 3
	//f[1]=1
	//f[2]=1
	//f[3]=1
	//f[4]=2
	//很明显可以让f[i]=f[i-1]
	//则可以先设置l=1
	//每次遍历的时候r++，同时 sum^=a[r]
	//直到a[r]==k的时候,l=r+1,sum=0
	//试试看吧！ 
	//但是，l不能从1开始，也有可能在不同的位置开始这个区间。
	//考虑优化区间运算
	//即快速地query(l,r)
	//线段树！ 
	//无修改，只有区间询问，所以不需要懒觉标记
	//10分钟写完线段树 
	//如何找到最大值呢？
	//query(l,r)是区间异或和 
	//写个O(n*n*logn)的暴力吧，60分够了 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//cout<<"区间["<<i<<","<<j<<"]的异或和为"<<query(1,1,n,i,j)<<endl;
			if(query(1,1,n,i,j)==k){
				qj[++cnt]=make_pair(i,j);
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		f[i]=1;
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i;j<=cnt;j++){
			int x=qj[i].first,y=qj[i].second,xx=qj[j].first,yy=qj[j].second;
			//如果[x,y]与[xx,yy]无交集则更新 
			if(y<xx||x>yy){
				f[j]=max(f[j],f[i]+1);
			}
		}
	}
	ll ans=0;
	//最长上升子序列模板（may） 
	for(int i=1;i<=cnt;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
