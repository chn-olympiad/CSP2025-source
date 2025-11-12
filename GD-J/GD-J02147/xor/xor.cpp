#include<bits/stdc++.h>
using namespace std;
int a[500010];
vector<pair<int,int> > p;
//unordered_map<int,int> mp;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; ++i) {
		scanf("%d",&a[i]);
	}
	int x;
	for(int i=1; i<=n; ++i) {
		if(a[i]==k) {
			p.push_back({i,i});
//			mp[i]=i;
			continue;
		}
		x=a[i];
		for(int j=i+1; j<=n; ++j) {
			if(a[j]==k) break;
			x=x^a[j];
			if(x==k) {
				p.push_back({i,j});
//				mp[i]=j;
				break;
			}
		}
	}
	int last=p[p.size()-1].second+100;
	int ans=0;
	for(int i=p.size()-1;i>=0;--i)
	{
		if(p[i].second<last)
		{
			ans++;
			last=p[i].first;
		}
	}
	cout<<ans;
	return 0;
}
