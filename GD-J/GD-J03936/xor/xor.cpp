#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[500005],dp[200005];
int cnt[500005];
vector<pair<int,int>>e;
int k;
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.second<b.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt[i]=(cnt[i-1]^a[i]);
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if((cnt[j]^cnt[i-1])==k){
				e.push_back(make_pair(i,j));
			}
		}
	}
	sort(e.begin(),e.end(),cmp);
	int r=0;
	for(int i=0;i<e.size();i++){
		if(e[i].first>r){
			ans++;
			r=e[i].second;
		}
	}
	cout<<ans;
	return 0;
} 
