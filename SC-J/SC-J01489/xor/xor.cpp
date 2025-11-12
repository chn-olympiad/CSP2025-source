#include<bits/stdc++.h>
#define ll long long
#define Suika 0
using namespace std;
const int N=500010;
int n,k,ans,pre,x,dp;//以i结尾，匹配的最大数量 
map<int,int>mp,mp1;
int main() {
//	double bgn=clock();
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin>>n>>k;
	mp1[0]=1;
	for(int i=1; i<=n; i++) {
		cin>>x;
		pre=pre^x;
		dp=ans;
		if(mp1.count(k^pre)) dp=max(dp,mp[k^pre]+1);
		ans=max(ans,dp);
		mp[pre]=max(mp[pre],dp);  
		mp1[pre]=1;
	}
	cout<<ans;
//	double ed=clock();
//	cout<<"\n"<<(ed-bgn)*1000/CLOCKS_PER_SEC;
	return Suika;
}