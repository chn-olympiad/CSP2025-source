#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int sum[N];
map<int,int> m;
map<int,bool> mp;
struct re{
	int l,r;
}p[N];
int idx;
int bd[N];
bool cmp(re a,re b){
	if(a.r-a.l==b.r-b.l) return a.l<b.l;
	return a.r-a.l<b.r-b.l;
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	mp[0]=1;
	m[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		if(mp[sum[i]^k]){
			p[++idx].l=m[sum[i]^k]+1;
			p[idx].r=i;
		}
		m[sum[i]]=i;
		mp[sum[i]]=1;
	}
	sort(p+1,p+idx+1,cmp);
	int R=0;
	int ans=0;
	for(int i=1;i<=idx;i++){
		bool r=0;
		for(int j=p[i].l;j<=p[i].r;j++){
			r|=bd[j];
		}
		if(!r){
			ans++;
			for(int j=p[i].l;j<=p[i].r;j++){
				bd[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
