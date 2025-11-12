#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5; 
pair<int,int> a[N * N];

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first > b.first;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> m >> n;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1,a + 1 + n * m,cmp);
	int k = 1;
	pair<int,int> ans;
	for(int i = 1;i <= n;i ++){
		if(i % 2){
			for(int j = 1;j <= m;j ++,k ++){
				if(a[k].second == 1){
					ans = {i,j};
				}
			}
		} else {
			for(int j = m;j >= 1;j --,k ++){
				if(a[k].second == 1){
					ans = {i,j};
				}
			}
		}
	}
	cout << ans.first << " " << ans.second;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
