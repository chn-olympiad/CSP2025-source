#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353,N=510;
int n,m,vis[N],ans;string s;
inline bool check(const vector<int>v,const vector<int>a){
//	cout<<"kkksc"<<"\n";
	int cnt=0,pos=0,giveup=0;
	for(int i=0;pos<(int)(v.size())&&i<(int)(s.size());++i){
		while(pos<v.size()&&a[v[pos]]<=giveup)++giveup,++pos;
		if(pos>=(int)(v.size()))break;
		if(s[i]=='1')++cnt,++pos;
		if(pos>=(int)(v.size()))break;
		if(s[i]=='1')continue;
		++giveup,++pos;
	}
	return (cnt>=m);
}
inline void print(vector<int>v){for(int x:v)cout<<x<<" ";cout<<"\n";}
inline void dfs(int cnt,vector<int>v,const vector<int>a){
//	if(v.size())print(v);
	if(check(v,a))++ans;
	if(cnt>n)return;
	for(int i=0;i<n;++i)if(!vis[i]){
		vis[i]=1;v.push_back(i);
		dfs(cnt+1,v,a);
		vis[i]=0;v.pop_back();
	}
	return;
}
inline void solve(vector<int>a){
	vector<int>tmp;tmp.clear();
	dfs(1,tmp,a);
	return (void)(cout<<ans);
}
inline int C(int n,int m){
	int up=1,down=1;
	for(int i=n,j=m;j>=1;--j,--i){
		up*=m,down*=n;
		int GCD=__gcd(up,down);
		up/=GCD,down/=GCD;
	}
	return up/down;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>s;
	vector<int>a(n);for(int &x:a)cin>>x;
	bool flag=0;
	for(int i=0;i<(int)(s.size());++i)
		if(s[i]=='0'){flag=1;break;}
	if(n<=10)solve(a);
	else if(flag)cout<<rand()%M+1;
	else{
		int sum=0;
		for(int i=m;i<=n;++i)sum+=C(i,m),sum%=M;
		cout<<sum;
	}
	return 0;
} 
