#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[300005][3];
priority_queue<int,vector<int>,greater<int> > pq[3];
void slv(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=0;i<=2;i++){
		while(pq[i].size()){
			pq[i].pop();
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int mx=0,se=1;
		if(a[i][0]<a[i][1]){
			swap(mx,se);
		}
		if(a[i][mx]<a[i][2]){
			se=mx;
			mx=2;
		}
		else if(a[i][2]>a[i][se]){
			se=2;
		}
		ans+=a[i][mx];
		pq[mx].push(a[i][mx]-a[i][se]);
	}
	if(pq[0].size()<=n/2&&pq[1].size()<=n/2&&pq[2].size()<=n/2){
		cout<<ans<<"\n";
		return;
	}
	int mx=0;
	for(int i=0;i<=2;i++){
		if(pq[i].size()>n/2){
			mx=i;//只会有一个不合法。 
		}
	}
	while(pq[mx].size()>n/2){
		int u=pq[mx].top();
		pq[mx].pop();
		ans-=u;
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club.txt","w",stderr);
	int t;
	cin>>t;
	while(t--){
		slv();
	}
	return 0;
}
/*
这里是T1. 
终局之战！ 
1机房什么全明星阵容。 
感觉可以直接贪心。 
14:45 过了。 
上联：社团招新不极端 
下联：员工招聘卡人数 
横批：完都完了 
*/
