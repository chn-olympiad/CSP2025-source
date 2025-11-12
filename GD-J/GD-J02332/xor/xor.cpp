#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
namespace{
	typedef pair<int,int> pii;
	int a[1000005],n,k;
	vector<int>e[1050005];
	int solve(vector<pii> v){//maximum intervals.
		int lst=0,cnt=0;
		for(auto &i:v) if(lst<i.x) cnt++,lst=i.y;
		return cnt;
	}
	void Main(){
		cin.tie(0)->sync_with_stdio(0);
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
		for(int i=1;i<=n;i++) e[a[i]].push_back(i);
		e[0].push_back(0);
		vector<pii>v;
		if(n<=5000){
			for(int i=1;i<=n;i++)
			for(auto &j:e[a[i]^k]) if(j<=i-1) v.push_back({j+1,i});
		}else for(int i=1;i<=n;i++) if((a[i]^a[i-1])==k) v.push_back({i,i});
		else{
			auto it=upper_bound(e[a[i]^k].begin(),e[a[i]^k].end(),i-1);
			if(it!=e[a[i]^k].begin()) v.push_back({*prev(it)+1,i});
		}
		cout<<solve(v);
	}	
} 
main(){Main();}
//T3 [60,85] pts 也还可以？ 

