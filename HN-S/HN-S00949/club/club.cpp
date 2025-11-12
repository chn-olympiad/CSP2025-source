#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,a[4];
vector<int>v[4];

void init(){
	n=ans=0;
	for(int j=1;j<=3;j++){
		a[j]=0;
		v[j].clear();
	}
}
void work(){
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		int mxi=1,mni=1;
		for(int j=1;j<=3;j++){
			cin>>a[j];
			if(a[j]>a[mxi])mxi=j;
			if(a[j]<a[mni])mni=j;
		}
		ans+=a[mxi];
		v[mxi].push_back(a[mxi]-(a[1]+a[2]+a[3]-a[mxi]-a[mni]));
	}
	for(int i=1;i<=3;i++){
		if(v[i].size()<=(n>>1))continue;
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size()-(n>>1);j++){
			ans-=v[i][j];
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T; cin>>T;
	while(T--)work();
	return 0;
}
