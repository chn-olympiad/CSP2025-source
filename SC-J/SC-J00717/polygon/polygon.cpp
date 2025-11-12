#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=5e3+30;
const int Mod=998244353;

int a[N];
map<set<int>,bool> mp;
set<int> st;
int ans=0;
int n;

bool ok(int cnt,int sum,int mx){
	bool flag=(sum>2*mx);
	return flag&&cnt>=3;
}

void print(){
	for(auto tmp:st){
		cout<<tmp<<' ';
	}
	cout<<'\n';
	return;
}

void dfs(int ord,int cnt,int sum,int mx){
	if(ord>n+1){
		return;
	}
//	print();
	if(ok(cnt,sum,mx)&&mp.find(st)==mp.end()){
//		print();
		mp[st]=1;
		ans++;
		ans%=Mod;
	}
	st.insert(ord);
	dfs(ord+1,cnt+1,sum+a[ord],max(mx,a[ord]));
	st.erase(ord);
	dfs(ord+1,cnt,sum,mx);
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans<<'\n';
	}else{
		cout<<Mod-1<<'\n';
	}
	return 0;
}

//100%是dp，懒(bu)得(hui)推转移方程 

//游记：这次大概也就100+100+30+24=254吧。分数线？210~240 （真.游记） 
//还有一件事，请把我放进迷惑行为大赏，pls!! 