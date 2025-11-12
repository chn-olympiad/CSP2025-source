#include "bits/stdc++.h"
using namespace std;
int n,k,ans;
int a[500005],s[500005],bz[500005];
vector<int> g[1050005];
struct node{
	int l,r,len;
};
vector<node> answer;
mt19937 rnd(time(0));
int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]^a[i],g[s[i]].push_back(i);
	for(int i=1;i<=n;i++){
		if(g[s[i-1]^k].empty()) continue;
		int l=0,r=g[s[i-1]^k].size()-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(g[s[i-1]^k][mid]>=i) r=mid;
			else l=mid+1;
		}
		if(g[s[i-1]^k][l]<i) continue;
		answer.push_back((node){i,g[s[i-1]^k][l],g[s[i-1]^k][l]-i+1});
	}
	int res=0;
	for(int i=1;i<=1e6/answer.size();i++){
		sort(answer.begin(),answer.end(),[](node x,node y){
			if(x.len==y.len) return x.l<y.r;
			return x.len<y.len;
		});
		memset(bz,0,sizeof bz);
		int ans=0;
		for(node x:answer){
			int flag=0;
			for(int i=x.l;i<=x.r;i++)
				if(bz[i]){flag=1;break;}
			if(flag) continue;
			ans++;
			for(int i=x.l;i<=x.r;i++) bz[i]=1;
		}
		res=max(res,ans);
		shuffle(answer.begin(),answer.end(),rnd);
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
}
