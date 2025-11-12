#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],sum,temp,cnt,nowr,ans;
map<int,int> mp;
struct node{
	int l,r;
}b[500005];
bool cmp(node a,node b){return a.r<b.r;}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		sum^=a[i];
		temp=(k^sum);
		if(mp[temp]||!temp){
			b[++cnt].l=mp[temp]+1;
			b[cnt].r=i;
		}
		mp[sum]=i;
	}
	sort(b+1,b+1+cnt,cmp);
	if(!cnt){
		cout<<0<<endl;
		return 0;
	}
	ans++;
	nowr=b[1].r;
	for(int i=2;i<=cnt;i++){
		if(b[i].l>nowr){
			nowr=b[i].r;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0; 
}
