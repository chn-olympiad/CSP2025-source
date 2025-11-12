#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][3],k[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	int sum=0,cnt[3]={0};
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])k[i]=0;
		if(a[i][1]>a[i][0]&&a[i][1]>=a[i][2])k[i]=1;
		if(a[i][2]>a[i][0]&&a[i][2]>a[i][1])k[i]=2;
		cnt[k[i]]++,sum+=a[i][k[i]];
		//cerr<<k[i]<<'\n';
	}
	if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2)return cout<<sum<<'\n',void();
	priority_queue<int>q;
	if(cnt[0]>n/2){
		for(int i=1;i<=n;i++){
			if(k[i]!=0)continue;
			q.push(max(a[i][1],a[i][2])-a[i][0]);
		}
		for(int i=1;i<=cnt[0]-n/2;i++){
			sum+=q.top();q.pop();
		}
	}
	if(cnt[1]>n/2){
		for(int i=1;i<=n;i++){
			if(k[i]!=1)continue;
			q.push(max(a[i][0],a[i][2])-a[i][1]);
		}
		for(int i=1;i<=cnt[1]-n/2;i++){
			sum+=q.top();q.pop();
		}
	}
	if(cnt[2]>n/2){
		for(int i=1;i<=n;i++){
			if(k[i]!=2)continue;
			q.push(max(a[i][0],a[i][1])-a[i][2]);
		}
		for(int i=1;i<=cnt[2]-n/2;i++){
			sum+=q.top();q.pop();
		}
	}
	cout<<sum<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//system("fc club5.ans club.out");return 0;
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	int T;cin>>T;while(T--)solve();
} 
