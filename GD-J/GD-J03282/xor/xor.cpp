#include<bits/stdc++.h>
#include<map>
#define int long long 
#define fi first
#define se second
using namespace std;
using PII=pair<int,int>;
int n,k;
int a[500005];
int pre[500005];
map<int,vector<int>>m;
bool cmp(PII x,PII y){
	return x.se<y.se;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	m[0].push_back(0);
	for( int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]^a[i];
		m[pre[i]].push_back(i);
	}
	vector<PII>ans;
	for( int i=1;i<=n;i++){
		if(m[pre[i]^k].size()!=0){
			for(int j:m[pre[i]^k]){
				if(j+1>i) continue;	
				ans.push_back({j+1,i});
			}
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	bool flag=true;
	int r;
	int cur=0;
	int res=0;
	while(flag){
		flag=false;
		r=ans[cur].se;
		res++;
		for(int i=cur+1;i<ans.size();i++){
			if(ans[i].fi>r){
				cur=i;
				flag=true;
				break;
			} 
		} 
	}
	cout<<res;
}
