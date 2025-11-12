#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NR = 1e5 + 5; 
int t,n;
int a[NR][5];
int d[NR];
int dd[NR];
vector <int> ve[5];
int cha[NR];
int sum;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		sum = 0;
		for(int i = 1;i <= 3;i++) ve[i].clear();
		
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxn = max(a[i][1],max(a[i][2],a[i][3]));
			sum += maxn;
			if(maxn == a[i][1]){
				d[i] = 1;
				if(a[i][2] >= a[i][3]) dd[i] = 2;
				else dd[i] = 3;
			}
			else if(maxn == a[i][2]){
				d[i] = 2;
				if(a[i][1] >= a[i][3]) dd[i] = 1;
				else dd[i] = 3;
			}
			else if(maxn == a[i][3]){
				d[i] = 3;
				if(a[i][1] >= a[i][2]) dd[i] = 1;
				else dd[i] = 2;
			}
			cha[i] = a[i][d[i]] - a[i][dd[i]];
			ve[d[i]].push_back(cha[i]);
		}
		if(ve[1].size() > n / 2){
			sort(ve[1].begin(),ve[1].end());
			for(int i = 0;i + n / 2 < ve[1].size();i++){
				sum -= ve[1][i];
			}
		}
		else if(ve[2].size() > n / 2){
			sort(ve[2].begin(),ve[2].end());
			for(int i = 0;i + n / 2 < ve[2].size();i++){
				sum -= ve[2][i];
			}
		}
		else if(ve[3].size() > n / 2){
			sort(ve[3].begin(),ve[3].end());
			for(int i = 0;i + n / 2 < ve[3].size();i++){
				sum -= ve[3][i];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
//100
