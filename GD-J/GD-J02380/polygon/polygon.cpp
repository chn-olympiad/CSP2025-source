#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int N=5005;
int p[N],pre[N],n,cnt;
unordered_map<string,bool> tp;
void dfs(int d,int sum,int mx,string nums){
	if(sum>2*mx){
		string ns(nums);
		while(ns.size()<n) ns+='a';
		if(tp.find(ns)==tp.end())
			cnt++,tp[ns]=1;
	}
	if(d>=n) return;
	dfs(d+1,sum,mx,nums+'a');
	dfs(d+1,sum+p[d+1],max(mx,p[d+1]),nums+char('a'+d+1));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool f1=0;
	cin>>n;
	For(i,1,n){
		cin>>p[i];
		if(p[i]!=1) f1=1;
	}
	sort(p+1,p+1+n);
	if(!f1){
		cnt=1;
		for(int i=1;i<=n;i++)
			cnt=cnt*2%998244353;
		cnt-=n;
		cnt-=n*(n-1)/2;
		cnt=(cnt+998244353)%998244353;
		cout<<cnt-1;
		return 0;
	}
	dfs(0,0,0,{});
	cout<<cnt%998244353;
	return 0;
}
