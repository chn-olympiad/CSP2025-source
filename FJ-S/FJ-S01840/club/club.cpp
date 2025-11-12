#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+5;

int n;
int a[N],b[N],c[N],d[N][5];
vector<int> h;

void solve()
{
	cin>>n;
	h.clear();
	int ans=0,c1=0,c2=0,c3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		d[i][1]=a[i],d[i][2]=b[i],d[i][3]=c[i];
		sort(d[i]+1,d[i]+1+3);
		ans+=d[i][3];
		if(d[i][3]==a[i]) c1++;
		else if(d[i][3]==b[i]) c2++;
		else if(d[i][3]==c[i]) c3++;
	}
	if(c1>n/2){
		for(int i=1;i<=n;i++){
			if(d[i][3]==a[i]) h.push_back(d[i][3]-d[i][2]);
		}	
		sort(h.begin(),h.end());
		for(int i=0;i<h.size();i++){
			if(i+1<=c1-n/2) ans-=h[i];
		}
	}
	else if(c2>n/2){
		for(int i=1;i<=n;i++){
			if(d[i][3]==b[i]) h.push_back(d[i][3]-d[i][2]);
		}
		sort(h.begin(),h.end());
		for(int i=0;i<h.size();i++){
			if(i+1<=c2-n/2) ans-=h[i];
		}
	}
	else if(c3>n/2){
		for(int i=1;i<=n;i++){
			if(d[i][3]==c[i]) h.push_back(d[i][3]-d[i][2]);
		}
		sort(h.begin(),h.end());
		for(int i=0;i<h.size();i++){
			if(i+1<=c3-n/2) ans-=h[i];
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

