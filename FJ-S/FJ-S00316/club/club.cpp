#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
const int N = 100050;
int n,v[N][4],w,ch[N],v1[N],dp[N][4];
int ans=0;
bool chose[N];
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	//先理解题目
	//题目的意思：
	//n个物品重量为1，三个背包，每个背包的最大容量为n/2，将每个物品装到{1,2,3}三个背包里的价值不一样
	//好了，两点40开始写代码，五点五十还没做完。。 
	bool flag1=1;
	memset(v,0,sizeof(v));
	memset(v1,0,sizeof(v1));
	memset(ch,0,sizeof(ch));
	memset(chose,0,sizeof(chose));
	ans=0;
	cin>>n;
	w=n/2;
	for(int i=1;i<=n;i++){
		cin>>v[i][1]>>v[i][2]>>v[i][3];
		if((v[i][2]!=v[i][3]||v[i][2]!=0)&&flag1){
			flag1=0;
		}
	}
	if(flag1){//特殊性质A
		for(int i=1;i<=n;i++){
			v1[i]=v[i][1];
		}
		ans=0;
		sort(v1+1,v1+1+n,cmp);
		for(int i=1;i<=w;i++){
			ans+=v1[i];
		}
		cout<<ans;
		return;
	}
	else{
		//设dp[i][j]表示遍历到i个物品，选择第j个部门
		int a=0,b=0,c=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j]=max(dp[i-1][1]+v[i][j],max(dp[i-1][2]+v[i][j],dp[i-1][3]+v[i][j]));
			}
		}
		for(int i=1;i<=3;i++){
			ans=max(ans,dp[n][i]);
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}

