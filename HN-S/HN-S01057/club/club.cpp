#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int t,n,p[N][5],v[N];long long ans;
vector<int> g;
void S(int x){
	if(x==n+1){
		long long cnt=0;
		for(auto it:g){
			cnt+=it;
		}
		ans=max(cnt,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(v[i]<n/2){
			g.push_back(p[x][i]);
			v[i]++;
			S(x+1);
			g.pop_back();
			v[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>p[i][j];
			}
		}
		S(0);
		cout<<ans<<'\n';
	}
	return 0;
}
