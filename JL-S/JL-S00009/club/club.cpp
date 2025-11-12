#include<bits/stdc++.h>
using namespace std;
#define int long long

int t;
int n;

pair <int,int> p1[100010],p2[100010],p3[100010];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>p1[i].second>>p2[i].second>>p3[i].second;
			p1[i].first=i;p2[i].first=i;p3[i].first=i;
		}
		int ans=0;
		if(n==2){
			ans=max(p1[1].second+p2[2].second,p1[1].second+p3[2].second);
			ans=max(ans,p2[1].second+p1[2].second);
			ans=max(ans,p2[1].second+p3[2].second);
			ans=max(ans,p3[1].second+p1[2].second);
			ans=max(ans,p3[1].second+p2[2].second);
			cout<<ans<<endl;
		}
		
	}
	
	
	return 0;
}
