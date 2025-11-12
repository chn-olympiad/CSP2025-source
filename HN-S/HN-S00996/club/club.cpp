#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100001;
#define endl '\n'
#define int long long

struct info{
	int x,y,z;
}a[N];

int t;
int n;
vector<pair<int,int>> d1,d2,d3;

inline bool cmp(const pair<int,int> &A,const pair<int,int> &B){
	return A.first>B.first;
}

inline void work(){
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		if (a[i].x>=a[i].y && a[i].x>=a[i].z)
			d1.push_back(make_pair(a[i].x-max(a[i].y,a[i].z),i));
		else if (a[i].y>=a[i].z && a[i].y>=a[i].x)
			d2.push_back(make_pair(a[i].y-max(a[i].x,a[i].z),i));
	}
	sort(d1.begin(),d1.end(),cmp);
	sort(d2.begin(),d2.end(),cmp);
	sort(d3.begin(),d3.end(),cmp);
	int ans=0;
	for (int i=0;i<d1.size() && i<n/2;i++)
		ans+=a[d1[i].second].x;
	for (int i=0;i<d2.size() && i<n/2;i++)
		ans+=a[d2[i].second].y;
	for (int i=n/2;i<d1.size();i++)
		ans+=a[d1[i].second].y;
	for (int i=n/2;i<d2.size();i++)
		ans+=a[d2[i].second].x;
	cout << ans << '\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while (t--) work();
	return 0;
}

