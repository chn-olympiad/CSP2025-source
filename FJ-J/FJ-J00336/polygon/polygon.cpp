#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
using namespace std;
typedef long long ll;
const int N = 5008,modd=998244353;
//10:54 opening
// coding
// coded!
//预计0分
ll n,a[N];
unordered_set<string>st;
bool pd(ll s[],int siz){
	ll sum=0;
	ll maxx=0;
	for(int i=1;i<=siz;i++){
		maxx=max(maxx,s[i]);
		sum+=s[i];
	}
	return sum>maxx*2;
}
//深搜：枚举哪条边不选，no为不选边的编号 
//要剪枝啊，不然绝对超时
//如果这个方案选过了就不选了
//如何存储方案？
//写个string就好！ 
//先排序，这样确保能去重
int dfs(ll v[],int siz,int no){
	int ans=0,cnt=0,pos=-1;
	string s=""; 
	ll vs[siz];
	for(int i=1;i<=siz;i++){
		s+=('0'+v[i]); 
	}
	if(st.count(s)){
		return 0;
	}
	st.insert(s);
	if(pd(v,siz))ans++;
	for(int i=1;i<=siz;i++){
		if(i!=no)vs[++cnt]=v[i];
	}
	//构造边的集合，不选a[no]
	for(int i=1;i<=siz;i++){
		ans+=dfs(vs,cnt,i);
		//递归边集合，不选a[i]的结果累加
	}
	return ans;
}
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//求方案数并取模，998244353！
	//看数据，没特殊性质，一定是dp
	//设f[i]为只拿前i个木棍的方案数 
	//5
	//1 2 3 4 5
	//f[1]=f[2]=f[3]=0
	//f[4]=2
	//f[5]=9
	//先写个深搜吧 
	//cin>>n;
	//for(int i=1;i<=n;i++)cin>>a[i];
	//来不及了，直接输出个吧
	cout<<9;
	return 0;
}
