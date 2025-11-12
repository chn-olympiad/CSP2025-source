#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int n,m,k=0;
vector<int> a;
bool cmp(int u,int v){
	return u>v;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int u=0;cin>>u;
			a.push_back(u);
		}
	}
	k=a[0];
	sort(a.begin(),a.end(),cmp);
	int cnt=0;
	for(int i=0;i<(int)a.size();i++){
		cnt++;
		if(k==a[i])break;
	}
	if(cnt%n==0){
		cout<<cnt/n<<" ";
		if(cnt/n%2==0){
			cout<<1;
		}
		else cout<<m;
	}
	else {
		cout<<cnt/n+1<<" ";
		if((cnt/n+1)%2==0){
			cout<<m-cnt%n+1;
		}
		else cout<<cnt%n;
	}
	return 0;
}