#include<bits/stdc++.h>
using namespace std;
int n, ans;
vector<vector<int>> m(201);
vector<int> num(4);

void go(int nu, int n_ans){
	if(nu == n){
		ans = max(ans, n_ans);
		return;
	}
	for(int i=0;i<3;i++){
		if(num[i] == n/2){
			continue;
		}
		num[i]++;
		go(nu+1, m[nu][i] + n_ans);
		num[i]--;
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		ans = 0;
		cin>>n;
		num.clear();
		for(int i=0;i<n;i++){
			m[i].clear();
		}
		
		for(int i=0;i<n;i++){
			for(int j=1;j<=3;j++){
				int x;
				cin>>x;
				m[i].push_back(x);
			}
		}
		go(0, 0);
		cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	}
	return 0;
}
