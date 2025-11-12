#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[3],ans[3][100005],a[3][100005];

void solve(){
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)cin>>a[j][i];
	}
	for(int i=1;i<=n;i++){
		int maxn=max(max(a[0][i],a[1][i]),a[2][i]);
		sum+=maxn;
		if(a[0][i]==maxn)ans[0][++cnt[0]]=a[0][i]-max(a[1][i],a[2][i]);
		else if(a[1][i]==maxn)ans[1][++cnt[1]]=a[1][i]-max(a[0][i],a[2][i]);
		else ans[2][++cnt[2]]=a[2][i]-max(a[1][i],a[0][i]);
	}
	if(cnt[0]>n/2){
		sort(ans[0]+1,ans[0]+cnt[0]+1);
		for(int i=1;i<=cnt[0]-n/2;i++){
//			int id=ans[0][i];
			sum-=ans[0][i];
		}
	}
	else if(cnt[1]>n/2){
		sort(ans[1]+1,ans[1]+cnt[1]+1);
		for(int i=1;i<=cnt[1]-n/2;i++){
//			int id=ans[1][i];
			sum-=ans[1][i];
		}
	}
	else if(cnt[2]>n/2){
		sort(ans[2]+1,ans[2]+cnt[2]+1);
		for(int i=1;i<=cnt[2]-n/2;i++){
//			int id=ans[2][i];
			sum-=ans[2][i];
		}
	}
	cout<<sum<<"\n";
	cnt[0]=cnt[1]=cnt[2]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}
/*
3
 2 4
 3 421
 4 324
 5 534
 6 351
 7 4
8 010
 9 010
 10 020
 11 020
 12 2
 13 109 8
 14 400
*/
