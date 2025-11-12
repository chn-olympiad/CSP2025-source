#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],pre[500005],l[500005],ans;
typedef pair<int,int> PII;
set<PII> s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=(pre[i-1]^a[i]);
	for(int i=n;i>=0;i--){
		int sum=(pre[i]^k);
		auto it=s.upper_bound({sum,0});
		while(1){
			if(it==s.end()) break;
			PII p=*it;
			if(p.first!=sum) break;
			l[p.second]=i+1;
			if(p.second==0) break;
			s.erase(it);
			it++;
		}
		s.insert({pre[i],i});
	}
	int la=0;
	for(int i=1;i<=n;i++){
		if(l[i]>la) la=i,ans++;
	}
	printf("%d",ans);
	return 0;
}
