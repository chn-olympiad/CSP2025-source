#include<bits/stdc++.h>
using namespace std;
int n,k;
long long int ans=0;
vector<int> a;
vector<int> p;
struct Quj{
	int l,r;
};
vector<Quj> q;
bool cmp(Quj a,Quj b){
	if(a.r==b.r){
		return a.l>b.l;
	}
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	q.clear();
	a.resize(n+1,0);
	p.resize(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((p[i-1]^p[j])==k){
				q.push_back({i,j});
			}
		}
	}
	sort(q.begin(),q.end(),cmp);
	int e=q[0].r;
	ans++;
	for(int i=1;i<q.size();i++){
		if(q[i].l>e){
			e=q[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
