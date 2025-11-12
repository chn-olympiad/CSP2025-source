#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using LL=long long;
using VI=vector<int>;
using AR=array<int,2>;
const int MOD=998244353;//有巨大模数，要开long long 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;//n是不可能爆int的 
	vector<LL> num(n+1);//保险起见开个LL（万一哪个地方运算中就溢出了呢） 
	REP(i,1,n)cin>>num[i];
	sort(begin(num)+1,end(num));//从小到大排序 
	int sz=num[n];//num的最大值由于排序，现在在末尾 
	vector<LL> dp(sz+1);//维护到最大值就可以了 
	LL choice=1,ans=0;dp[0]=1;//choice维护总选法，初始的时候有一种（即不选），长度和为0 
	REP(i,1,n){//挨个定为最大值  
		if(i>=3){
			//只有在不少于3根的时候才统计 
			//被统计（即没被去掉）的选法一定选择了不少于3根，因为少于3根时其余木棍长度和显然无法超过当前木棍 
			LL nowchoice=choice;//副本复制 
			for(int j=0;j<=num[i];j++)nowchoice=(nowchoice+MOD-dp[j])%MOD;//去掉所有长度和小于等于当前长度的选法 
			(ans+=nowchoice)%=MOD;//统计 
		}
		for(int j=sz;j>=num[i];j--)(dp[j]+=dp[j-num[i]])%=MOD;//滚动数组，防止污染，从后往前遍历 
		(choice*=2)%=MOD;//确认已随处取模 
	}
	cout<<ans;
	return 0;
}
//首先转换条件：即要求最长的木棍（有多根就任取一根作为最长）小于其余木棍长度之和
//那么就可以对长度排序，从小到达枚举最大值
//排序的目的是使得其余木棍的位置一定在最长木棍之前
//也就是要统计在最长的木棍之前有多少种选法使得长度之和大于最长木棍的长度
//数据范围启发dp，支持平方级算法 
//当前考虑第i根木棍作为最长的木棍
//直接统计前面的选法当然是会T飞的
//不妨按长度之和递推统计选法
//也就是维护dp数组，dp[s]记录前面长度和为s的选法
//转移的时候枚举每一种长度和，然后T飞
//注意到a不超过1000，因此可以只维护到a中的最大值
//这样能够（也只能）求出长度之和小于等于最长木棍长度的选法数量
//用总数量减掉它就得到了
//单次维护、统计效率为5000
//（为什么我的第一反应是BIT） 
//11-01 09:18:18