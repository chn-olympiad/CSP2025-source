#include<bits/stdc++.h>
using namespace std;
int a[500010],sum[500010];
struct tl{
	int st;
	int en;
};
vector<tl> tt;
map<int,vector<int>> mp;
int cmp(tl x,tl y){
	return x.en<y.en;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0,d=0;
	mp[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		int x=sum[i]^k;
		for(int j:mp[x]){
			tl _;
			_.st=j+1;
			_.en=i;
			tt.push_back(_);
		}
		mp[sum[i]].push_back(i);
	}
	sort(tt.begin(),tt.end(),cmp);
	int can_start_at=1;
	for(auto i:tt){
		if(i.st>=can_start_at){
			ans++;
			can_start_at=i.en+1;
		}
	}
	cout<<ans;
	return 0;
} 
