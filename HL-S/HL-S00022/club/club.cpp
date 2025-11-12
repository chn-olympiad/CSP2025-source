#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	vector<vector<pair<int,int>>> humans;
	int t,n,ans,_minus;
	vector<vector<int>> cnt(3);
	vector<int> les;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		ans=0;
		_minus=0;
		cnt[0].resize(0);
		cnt[1].resize(0);
		cnt[2].resize(0);
		les.resize(0);
		humans.resize(n,vector<pair<int,int>>(3));
		for(int j=0;j<n;j++){
			cin>>humans[j][0].first>>humans[j][1].first>>humans[j][2].first;
			humans[j][0].second=0;
			humans[j][1].second=1;
			humans[j][2].second=2;
			sort(humans[j].begin(),humans[j].end());
			reverse(humans[j].begin(),humans[j].end());
			ans+=humans[j][0].first;
			cnt[humans[j][0].second].push_back(j);
		}
		for(int j=0;j<3;j++){
			if(cnt[j].size()>n/2){
				for(int k=0;k<cnt[j].size();k++){
					les.push_back(humans[cnt[j][k]][0].first);
					les[k]-=humans[cnt[j][k]][1].first;
				}
				_minus=cnt[j].size()-n/2;
			}
		}
		for(int j=0;j<_minus;j++){
			ans-=les[j];
		}
		cout<<ans<<'\n';
	}
	return 0;
}