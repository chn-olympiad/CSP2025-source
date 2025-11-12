#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int T,n,a[N][3];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	for(cin>>T;T--;){
		cin>>n;
		vector<int>v[3]; 
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int x=max({a[i][0],a[i][1],a[i][2]});
			ans+=x;
			if(x==a[i][0])		v[0].push_back(x-max(a[i][1],a[i][2]));
			else if(x==a[i][1])	v[1].push_back(x-max(a[i][0],a[i][2]));
			else				v[2].push_back(x-max(a[i][0],a[i][1]));
		}
		for(int i=0;i<=2;i++)if(v[i].size()>n/2){
			int k=v[i].size()-n/2;
			sort(v[i].begin(),v[i].end());
			for(int j=0;j<k;j++)ans-=v[i][j];
		}
		cout<<ans<<'\n';
	}
}
