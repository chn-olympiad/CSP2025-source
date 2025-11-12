#include<bits/stdc++.h>
#define pii pair<int,int>
#define fr first
#define sc second
using namespace std;
const int N=1e5+10;
typedef long long ll;
inline int read(){
	int res=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch))
		flag=(ch=='-')?-1:1,
		ch=getchar();
	while(isdigit(ch))
		res=(res<<3)+(res<<1)+(ch^48),
		ch=getchar();
	return res*flag;
}
int T,n,acnt,bcnt,ccnt;
int ast,bst,cst;
ll asum,bsum,csum,ans;
struct Node{
	ll a,b,c,lable,delta;
	Node(){
		
	}
	Node(int x,int y,int z):a(x),b(y),c(z){
		
	}
	inline int cal_lable(){
		if(a>=b and a>=c) return 3;
		else if(b>=a and b>=c) return 2;
		else return 1;
	}
	inline int cal_delta(){
		if(lable==3) return min(a-b,a-c);
		else if(lable==2) return min(b-a,b-c);
		return min(c-a,c-b);
	}
	friend bool operator<(Node x,Node y){
		if(x.lable!=y.lable) return x.lable>y.lable;
		else return x.delta>y.delta;
	}
}node[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		ans=0,acnt=0,bcnt=0,ccnt=0;
		ast=0,bst=0,cst=0;asum=0,bsum=0,csum=0;
		for(int x,y,z,i=1;i<=n;i++)
			x=read(),y=read(),z=read(),
			node[i]={x,y,z},
			node[i].lable=node[i].cal_lable(),
			node[i].delta=node[i].cal_delta();
		sort(node+1,node+1+n);
		for(int i=1;i<=n;i++){
			if(node[i].lable==3) ast=ast?ast:i,++acnt,asum+=node[i].a;
			else if(node[i].lable==2) bst=bst?bst:i,++bcnt,bsum+=node[i].b;
			else cst=cst?cst:i,++ccnt,csum+=node[i].c;
		}
		if(acnt>(n>>1)){
			ans+=bsum+csum;
			for(int cnt=0,i=ast;node[i].lable==3;i++){
				if(cnt<(n>>1))	++cnt,ans+=node[i].a;
				else ans+=max(node[i].b,node[i].c);
			}
		}
		else if(bcnt>(n>>1)){
			ans+=asum+csum;
			for(int cnt=0,i=bst;node[i].lable==2;i++){
				if(cnt<(n>>1))	++cnt,ans+=node[i].b;
				else ans+=max(node[i].a,node[i].c);
			}
		}
		else if(ccnt>(n>>1)){
			ans+=asum+bsum;
			for(int cnt=0,i=cst;node[i].lable==1;i++){
				if(cnt<(n>>1))	++cnt,ans+=node[i].c;
				else ans+=max(node[i].a,node[i].b);
			}
		}
		else ans=asum+bsum+csum;
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
1
4
5 1 1
5 1 1
5 1 1
999 1000 1
*/
/*
每一个三元组各取最大，就是最大的情况 
分成三类后，只会有一类出现多出来的情况
这一类中，相当于多出来的部分分到另外两类
分过去，就会减少这一类到另外两类差的最小值 
*/
