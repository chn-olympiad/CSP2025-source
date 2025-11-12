#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int a1[maxn],a2[maxn],a3[maxn];
vector<pair<int,int> > s1;
vector<pair<int,int> > s2;
vector<pair<int,int> > s3;
void init(){
	while(!s1.empty()){
		s1.pop_back();
	}
	while(!s2.empty()){
		s2.pop_back();
	}
	while(!s3.empty()){
		s3.pop_back();
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			int mx = max(a1[i],max(a2[i],a3[i]));
			int del = 0;
			if(mx == a1[i]){
				del = a1[i] - max(a2[i],a3[i]);
				s1.push_back(make_pair(del,a1[i]));
			}
			else if(mx == a2[i]){
				del = a2[i] - max(a1[i],a3[i]);
				s2.push_back(make_pair(del,a2[i]));
			}
			else{
				del = a3[i] - max(a2[i],a1[i]);
				s3.push_back(make_pair(del,a3[i]));
			}
		}
		int ans = 0;
		for(auto v : s1){
			ans += v.second;
		}
		for(auto v : s2){
			ans += v.second;
		}
		for(auto v : s3){
			ans += v.second;
		}
		if(s3.size() > n / 2){
			sort(s3.begin(),s3.end());
			for(int i = 0;i < s3.size() - n / 2;i ++){
				ans -= s3[i].first;
			}
		}
		if(s2.size() > n / 2){
			sort(s2.begin(),s2.end());
			for(int i = 0;i < s2.size() - n / 2;i ++){
				ans -= s2[i].first;
			}
		}
		if(s1.size() > n / 2){
			sort(s1.begin(),s1.end());
			for(int i = 0;i < s1.size() - n / 2;i ++){
				ans -= s1[i].first;
			}
		}
		cout<<ans<<endl;
		init();
	}
	return 0;
} 
