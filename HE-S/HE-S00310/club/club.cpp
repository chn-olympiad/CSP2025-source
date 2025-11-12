#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 100005;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	vector<int> res;
	cin >> t;
	while(t--){
		int a[MAXN][4],n;
		cin >> n;
		vector<vector<pair<int,int>>> pairA;
		int ans = 0;
		for(int i = 1;i<=n;i++){
			vector<pair<int,int>> paircurr;
			for(int j = 1;j<=3;j++){
				cin >> a[i][j];
				paircurr.push_back({a[i][j],j});
			}
			sort(paircurr.begin(),paircurr.end());
			pairA.push_back(paircurr);
		}
		int ans1=0,ans2=0,ans3=0;
		for(int i = 0;i<pairA.size();i++){
			ans+=pairA[i][2].first;
			if(pairA[i][2].second==1) ans1++;
			if(pairA[i][2].second==2) ans2++;
			if(pairA[i][2].second==3) ans3++;
		}
		//明确一个性质：当某个社团的人数多于n/2时，那其他两个社团人数绝对不可能超过n/2 
		int than = n/2;
		if(ans1>than){
			vector<int> curr;
			for(int i = 0;i<n;i++){
				if(pairA[i][2].second==1){
					curr.push_back(i);
				}
			}
			for(int i = 0;i<curr.size();i++){
				if(ans1>than){
					ans1--;
					ans-=pairA[curr[i]][2].first;
					int newclub = pairA[curr[i]][1].second;
					if(newclub==2){
						if(ans2>=than){
							ans+=pairA[curr[i]][0].first;
							ans3++;
						}
						else{
							ans+=pairA[curr[i]][1].first;
							ans2++;
						}
					}
					if(newclub==3){
						if(ans3>=than){
							ans+=pairA[curr[i]][0].first;
							ans2++;
						}
						else{
							ans+=pairA[curr[i]][1].first;
							ans3++;
						}
					}
				}
				else{
					break;
				}
			}
		}
		if(ans2>than){
			vector<int> curr;
			for(int i = 0;i<n;i++){
				if(pairA[i][2].second==2){
					curr.push_back(i);
				}
			}
			for(int i = 0;i<curr.size();i++){
				if(ans2>than){
					ans2--;
					ans-=pairA[curr[i]][2].first;
					int newclub = pairA[curr[i]][1].second;
					if(newclub==1){
						if(ans1>=than){
							ans3++;
							ans+=pairA[curr[i]][0].first;
						}
						else{
							ans+=pairA[curr[i]][1].first;
							ans1++;
						}
					}
					if(newclub==3){
						if(ans3>=than){
							ans1++;
							ans+=pairA[curr[i]][1].second;
						}
						else{
							ans+=pairA[curr[i]][1].first;
							ans3++;
						}
					}
				}
				else{
					break;
				}
			}
		}
		if(ans3>than){
			vector<int> curr;
			for(int i = 0;i<n;i++){
				if(pairA[i][2].second==2){
					curr.push_back(i);
				}
			}
			for(int i = 0;i<curr.size();i++){
				if(ans2>than){
					ans2--;
					ans-=pairA[curr[i]][2].first;
					int newclub = pairA[curr[i]][1].second;
					if(newclub==1){
						if(ans1>=than){
							ans+=pairA[curr[i]][0].first;
							ans2++;
						}
						else{
							ans+=pairA[curr[i]][1].first;
							ans1++;
						}
					}
					if(newclub==2){
						if(ans2>=than){
							ans+=pairA[curr[i]][0].first;
							ans2++;
						}
						else{
							ans+=pairA[curr[i]][1].first;
							ans2++;
						}
					}
				}
			}
		}
		res.push_back(ans);
	}
	for(int i = 0;i<res.size();i++){
		cout << res[i] << endl;
	}
	return 0;
}
