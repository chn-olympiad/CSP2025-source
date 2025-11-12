#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int Rd;

inline Rd read(){Rd xxx=0,yyy=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}

const int maxn=500005;

int n,k,ans;
ll a[maxn];
int dp[maxn];
map<int,int>mp;
int bt[maxn];

void add(int x,int y){
	while(x<=n)
		bt[x]=max(bt[x],y),
		x+=(-x)&x;
	return ;
}int query(int x){
	int ret=0;
	while(x)
		ret=max(ret,bt[x]),
		x-=(-x)&x;
	return ret;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	/*动态规划优化、平衡树、树状数组*/
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		a[i]=read();
	int now=0;
	mp[0]=0;
	//in_it
	for(int i=1;i<=n;i++){
		now^=a[i];
		if(mp.find(now^k)!=mp.end())	//if_find_the_pre_before_i_that_can_xor_with_pre_of_i
			dp[i]=query(mp[now^k])+1,	//query_the_dp[0~the_pre's_xb] & add_1
			add(i,dp[i]);				//update
		mp[now]=i;//keep_max
	}
	for(int i=1;i<=n;i++)
		ans=max(dp[i],ans);
	//solve
	cout<<ans;
	//put_it
	return 0;
}

