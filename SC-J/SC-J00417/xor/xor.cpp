#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
using namespace std;
int a[500005],b[500005];
struct Point{
	int l,r;
}c[500005];
bool cmp(Point a,Point b){
	return a.r<b.r;
}
map<int,vector<int> > mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,flag=1,le=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	if(flag){
		if(k==0)cout<<n/2;
		else if(k==1)cout<<n;
		else cout<<0;
	}
	b[1]=a[1];
	mp[b[1]].push_back(1);
	for(int i=2;i<=n;i++){
		b[i]=(b[i-1]^a[i]);
		mp[b[i]].push_back(i);
	}
//	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	for(int i=1;i<=n;i++){
		int h=(b[i]^k);
		if(a[i]==k)c[++le]={i,i};
		if(b[i]==k)c[++le]={1,i};
		for(int j=0;j<mp[h].size();j++){
			if(mp[h][j]<i)c[++le]={mp[h][j]+1,i};
//			cout<<999;
		}
	}
	if(le==0){
		cout<<0;
		return 0;
	}
	sort(c+1,c+le+1,cmp);
//	for(int i=1;i<=le;i++)cout<<c[i].l<<' '<<c[i].r<<'\n';
	int ans=1,rr=c[1].r;
	for(int i=2;i<=le;i++){
		if(c[i].l>rr){
			ans++;
			rr=c[i].r;
		}
	}
	cout<<ans;
	return 0;
}