#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int ans[1005][1005];
queue<int> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		q.push(a[i]);
	}
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++){
				ans[i][j]=q.front();
				q.pop();
			}
		}else{
			for(int i=n;i>=1;i--){
				ans[i][j]=q.front();
				q.pop();
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==r){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
