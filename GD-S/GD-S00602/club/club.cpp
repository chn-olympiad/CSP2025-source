#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][5];
long long ans;
bool cmp(int x,int y){
	return x>y;
}
void solve1(){
	int b[100005];
	for (int i=1;i<=n;i++) b[i]=a[i][1];
	sort(b+1,b+1+n,cmp);
	for (int i=1;i<=n/2;i++) ans+=b[i];
	cout<<ans<<'\n';
	return;
}
void solve2(){
	pair<int,int> b[100005];
	for (int i=1;i<=n;i++){
		b[i].first=a[i][1]-a[i][2];
		b[i].second=i;
	}
	sort(b+1,b+1+n);
	for (int i=1;i<=n/2;i++){
		ans+=a[b[i].second][2];
	}
	for (int i=n/2+1;i<=n;i++){
		ans+=a[b[i].second][1];
	}
	cout<<ans<<'\n';
	return;
}
void solve3(){
	int sum[4]={0};
	priority_queue<pair<int,int>> q[4];
	for (int i=1;i<=n;i++){
		int p=0;
		if (a[i][1]>a[i][2] && a[i][1]>a[i][3]) p=1; 
		if (a[i][2]>a[i][1] && a[i][2]>a[i][3]) p=2;
		if (a[i][3]>a[i][1] && a[i][3]>a[i][2]) p=3;
		ans+=a[i][p];
		q[p].push({-a[i][p],i});
		sum[p]++;
	}
	int p=0;
	if (sum[1]>n/2) p=1;
	if (sum[2]>n/2) p=2;
	if (sum[3]>n/2) p=3;
	while(q[p].size()>n/2){
		int x=q[p].top().first,y=q[p].top().second;
		q[p].pop();
		ans-=-x;
		if (p==1) ans+=max(a[y][2],a[y][3]);
		if (p==2) ans+=max(a[y][1],a[y][3]);
		if (p==3) ans+=max(a[y][1],a[y][2]);
	} 
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//no sir!!!!!!!!!!!!!!!!!!!!!!!
	cin>>T;
	while(T--){
		cin>>n;
		bool flag1=0,flag2=0;
		ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if (a[i][2]!=0 || a[i][3]!=0) flag1=1;
			if (a[i][3]!=0) flag2=1;
		}
		if (flag1==0){
			solve1();
			continue;
		}
		if (flag2==0){
			solve2();
			continue;
		}
		solve3();
	}
	return 0;
}
