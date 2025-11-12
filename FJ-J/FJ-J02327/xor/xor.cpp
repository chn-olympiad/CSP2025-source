#include<bits/stdc++.h>
using namespace std;
struct pii{
	int l,r;
};
bool operator>(const pii &x,const pii &y){		
	if(x.l==y.l)return x.r<y.r;
	return x.l<y.l;
}
bool operator<(const pii &x,const pii &y){		
	if(x.l==y.l)return x.r>y.r;
	return x.l>y.l;
}
int p[500005],a[500005],n,k,ans;
priority_queue<pii>qx,qy;
map<pii,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=p[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((p[j]^p[i-1])==k)
				qx.push({i,j}),
				qy.push({j,i});
	int r=1;
	while(r<=n){
		pii f;
		while(qx.top().l<r&&qx.size()){mp[qx.top()]=1;qx.pop();}
		f={qy.top().r,qy.top().l};
		while(mp.find(f)!=mp.end()&&qy.size())
			qy.pop(),f={qy.top().r,qy.top().l};
		if(mp[{qy.top().r,qy.top().l}]==1)break;
		r=qy.top().l+1,ans++;qy.pop();
	}
	cout<<ans;
}