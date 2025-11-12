#include<bits/stdc++.h>

using namespace std;

int stu[10050];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		long long ans=0;
		int n;cin>>n;
		memset(stu , 0, sizeof(stu));
		int x, y;
		for(int i=1; i<=n; i++){
				cin>>stu[i]>>x>>y;
		}	
		sort(stu +1, stu+n+1);
		
		for(int i=n; i>n/2; i--){
			ans += stu[i];
	}
		cout<<ans;
	}

	return 0;
}
