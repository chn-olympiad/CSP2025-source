#include<bits/stdc++.h>
using namespace std;

#define int long long

// ±àºÅ£¬¹±Ï× 
typedef pair<int,int> pii;

struct Person{
	vector<pii> pref;
	Person(){
		pref.assign(3,{0,0});
	}
	
	pii& operator [] (unsigned int i){
		return pref[i];
	}
	
	bool operator < (Person b)const{
		return pref[0].second>b[0].second;
	}
};

bool cmp(pii a, pii b){
	return a.second>b.second;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		
		vector<Person> seq(n);
		for (int i=0;i<n;i++){
			cin>>seq[i][0].second>>seq[i][1].second>>seq[i][2].second;
			seq[i][0].first = 0;seq[i][1].first = 1;seq[i][2].first = 2;
			sort(seq[i].pref.begin(), seq[i].pref.end(), cmp);
			seq[i].pref.pop_back();
		}
		int ans = 0;
		
		array<vector<int>,3> a;
		for (Person& p:seq){
			a[p[0].first].push_back(p[0].second-p[1].second);
			ans += p[0].second;
		}
		
		sort(a[0].begin(),a[0].end());
		sort(a[1].begin(),a[1].end());
		sort(a[2].begin(),a[2].end());
		
		for (int i=0;i<3;i++){
			if(a[i].size()>(n/2)){
				int d = a[i].size()-(n/2);
				for (int j=0;j<d;j++) ans -= a[i][j];
			}
		}

		cout<<ans<<'\n';
	}
	
	return 0; 
}
