#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int sum;
bool cmp(pair<int,int> a,pair<int,int> b) {
	return a.first>b.first;
}
vector<pair<int,int> > a1,a2;
vector<pair<int,int> > b1,b2;
vector<pair<int,int> > c1,c2;
int vis[N];
int main() {
	int a=0,b=0,c=0,tmp1,tmp2,tmp3;
	int n,t;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		a=0,b=0,c=0,sum=0;
		cin>>n;
		a1.clear();
		a2.clear();
		b1.clear();
		b2.clear();
		c1.clear();
		c2.clear();
		memset(vis,0,sizeof(vis));
		for(int i=1; i<=n; i++) {
			cin>>tmp1>>tmp2>>tmp3;
			if(tmp1>=tmp2 && tmp1>=tmp3) sum+=tmp1,a++,a1.push_back({tmp2-tmp1,i}),a2.push_back({tmp3-tmp1,i});
			else if(tmp2>=tmp1 && tmp2>=tmp3) sum+=tmp2,b++,b1.push_back({tmp1-tmp2,i}),b2.push_back({tmp3-tmp2,i});
			else if(tmp3>=tmp2 && tmp3>=tmp1) sum+=tmp3,c++,c1.push_back({tmp2-tmp3,i}),c2.push_back({tmp1-tmp3,i});
		}
		if(a>n/2) {
			sort(a1.begin(),a1.end(),cmp);
			sort(a2.begin(),a2.end(),cmp);
			int p1=0,p2=0;
			for(int i=1; i<=a-n/2; i++) {
				while(vis[a1[p1].second]) p1++;
				while(vis[a2[p2].second]) p2++;
				if(a1[p1].first>=a2[p2].first) vis[a1[p1].second]=1,sum+=a1[p1++].first;
				else  vis[a2[p2].second]=1,sum+=a2[p2++].first;
			}
		}
		if(b>n/2) {
			sort(b1.begin(),b1.end(),cmp);
			sort(b2.begin(),b2.end(),cmp);
			int p1=0,p2=0;
			for(int i=1; i<=b-n/2; i++) {
				while(vis[b1[p1].second]) p1++;
				while(vis[b2[p2].second]) p2++;
				if(b1[p1].first>=b2[p2].first) vis[b1[p1].second]=1,sum+=b1[p1++].first;
				else  vis[b2[p2].second]=1,sum+=b2[p2++].first;
			}
		}
		if(c>n/2) {
			sort(c1.begin(),c1.end(),cmp);
			sort(c2.begin(),c2.end(),cmp);
			int p1=0,p2=0;
			for(int i=1; i<=c-n/2; i++) {
				while(vis[c1[p1].second]) p1++;
				while(vis[c2[p2].second]) p2++;
				if(c1[p1].first>=c2[p2].first) vis[c1[p1].second]=1,sum+=c1[p1++].first;
				else  vis[c2[p2].second]=1,sum+=c2[p2++].first;
			}

		}
		cout<<sum<<endl;
	}
	return 0;
}
