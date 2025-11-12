#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const int inf=1e9+7;
priority_queue<int> pq;
int a[N][4];
//Tanxin

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		ll ans=0;
		int cnt1=0;
		int cnt2=0;
		int cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maxa=max({a[i][1],a[i][2],a[i][3]});
			ans+=maxa;
			if(maxa==a[i][1]){
				cnt1++;
			}else if(maxa==a[i][2]){
				cnt2++;
			}else{
				cnt3++;
			}
		}
		int pos=-1;
		int need=0;
		if(cnt1>n/2) pos=1,need=cnt1-n/2;
		if(cnt2>n/2) pos=2,need=cnt2-n/2;
		if(cnt3>n/2) pos=3,need=cnt3-n/2;
		if(pos==-1){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int maxa=max({a[i][1],a[i][2],a[i][3]});
			if(maxa==a[i][pos]){
				int p=-inf;
				if(pos!=1) p=max(p,a[i][1]-a[i][pos]);
				if(pos!=2) p=max(p,a[i][2]-a[i][pos]);
				if(pos!=3) p=max(p,a[i][3]-a[i][pos]);
				pq.push(p);
			}
		}
		while(need--){
			ans+=pq.top();
			pq.pop();
		}
		cout<<ans<<"\n";
		while(!pq.empty()) pq.pop();
	}
}
