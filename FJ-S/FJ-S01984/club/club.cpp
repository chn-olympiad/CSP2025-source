#include<bits/stdc++.h>
using namespace std;
int n,cnt[3],ans;
pair<int,int> a[100086][3];
void work(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0].first>>a[i][1].first>>a[i][2].first;
		a[i][0].second=0,a[i][1].second=1,a[i][2].second=2;
		sort(a[i],a[i]+3,greater<pair<int,int> >());
	}
	for(int i=1;i<=n;i++){
		int p=a[i][0].second,t=0;
		if(cnt[p]>=n/2)p=a[i][1].second,t=1;
		if(cnt[p]>=n/2)p=a[i][2].second,t=2;
		cnt[p]++;
		ans+=a[i][t].first;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)work();
	return 0;
}

