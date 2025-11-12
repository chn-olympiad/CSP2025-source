#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;

int n,a[N][5],ans;
vector<int>d1,d2,d3;
inline bool cmp(int x,int y){
	return a[x][4]>a[y][4];
}

inline void solve(){
	scanf("%d",&n);
	ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])d1.push_back(i),ans+=a[i][1],a[i][4]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])d2.push_back(i),ans+=a[i][2],a[i][4]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		else d3.push_back(i),ans+=a[i][3],a[i][4]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
	}
	if(d1.size()>n/2){
		sort(d1.begin(),d1.end(),cmp);
		while(d1.size()>n/2){
			int x=d1[d1.size()-1];
			ans-=a[x][4];
			d1.pop_back();
		}
	}
	else if(d2.size()>n/2){
		sort(d2.begin(),d2.end(),cmp);
		while(d2.size()>n/2){
			int x=d2[d2.size()-1];
			ans-=a[x][4];
			d2.pop_back();
		}
	}
	else if(d3.size()>n/2){
		sort(d3.begin(),d3.end(),cmp);
		while(d3.size()>n/2){
			int x=d3[d3.size()-1];
			ans-=a[x][4];
			d3.pop_back();
		}
	}
	d1.clear();
	d2.clear();
	d3.clear();
	printf("%lld\n",ans);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
//—©¿ÚΩ¥  ø®Õ€“¡  ¥Ûsuki
//—©¿ÚΩ¥  ø®Õ€“¡  ¥Ûsuki
