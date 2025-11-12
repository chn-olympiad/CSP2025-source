#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][3];
vector<pair<int,int> > v0,v1,v2;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int T;scanf("%d",&T);
while(T--){
	scanf("%d",&n);v0.clear();v1.clear();v2.clear();
	int sum=0;
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)  scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			v0.push_back({a[i][0],min(a[i][0]-a[i][1],a[i][0]-a[i][2])});
			sum+=a[i][0];
		}
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			v1.push_back({a[i][1],min(a[i][1]-a[i][0],a[i][1]-a[i][2])});
			sum+=a[i][1];
		}
		else{
			v2.push_back({a[i][2],min(a[i][2]-a[i][1],a[i][2]-a[i][0])});
			sum+=a[i][2];
		}
	}
	if(v0.size()>n/2){
		int len=v0.size();
		sort(v0.begin(),v0.end(),[](pair<int,int> x,pair<int,int> y){return x.second>y.second;});
		while(len>n/2){
			sum-=v0.back().second;v0.pop_back();
			len--;
		}
	}
	if(v1.size()>n/2){
		int len=v1.size();
		sort(v1.begin(),v1.end(),[](pair<int,int> x,pair<int,int> y){return x.second>y.second;});
		while(len>n/2){
			sum-=v1.back().second;v1.pop_back();
			len--;
		}
	}
	if(v2.size()>n/2){
		int len=v2.size();
		sort(v2.begin(),v2.end(),[](pair<int,int> x,pair<int,int> y){return x.second>y.second;});
		while(len>n/2){
			sum-=v2.back().second;v2.pop_back();
			len--;
		}
	}
	printf("%d\n",sum);
}
	return 0;
}
//’‚≥°CSP-S 
