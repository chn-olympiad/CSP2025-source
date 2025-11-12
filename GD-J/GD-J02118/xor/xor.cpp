#include<bits/stdc++.h>
const int N = 5e5+10;
using namespace std;
int n,k,a[N],s[N];
unordered_map<int,vector<int> > ma;
int ans=INT_MIN;
// getss is O(log n)
// all is O(n log n)

int getss(int now){
	int l=s[now-1]^k;
//	cout<<"l="<<l;
	int d=lower_bound(ma[l].begin(),ma[l].end(),now)-ma[l].begin();
//	cout<<" d="<<d<<endl;
	if(d>=ma[l].size()) return 0;
	else return ma[l][d];
}
void dfs(int now,int sum){
//	cout<<now<<endl;
	if(now==n+1){
		ans=max(ans,sum);
		return ;
	}
	int st=getss(now),p;
	if(st==0) { dfs(now+1,sum); return ;}
//	cout<<now<<" "<<st<<endl;
	for(int i=now+1;i<=st;i++){
		p=getss(i);
//		cout<<i<<endl;
		if(p!=0&&p<=st) st=p;
	}
	if(st!=0) dfs(st+1,sum+1);
	else dfs(now+1,sum); // in the end 
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin.sync_with_stdio(false),cin.tie(0);
	cin>>n>>k;
	s[0]=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		ma[s[i]].push_back(i);
	}
	for(auto &vs:ma){ // O( n^2 log n ) smaller  -> O( n log n)
		sort(vs.second.begin(),vs.second.end()); 
//		cout<<vs.first<<" "<<vs.second.size()<<endl;
	}
	dfs(1,0);
	
	cout<<ans;
	return 0;
}

