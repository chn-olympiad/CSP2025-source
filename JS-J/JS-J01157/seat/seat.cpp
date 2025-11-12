#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int cnt[1005];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ans;
	cin>>ans;
	for (int i=1;i<n*m;i++) cin>>cnt[i];
	cnt[n*m]=ans;
	sort(cnt+1,cnt+n*m+1,cmp);
	int k=1;
	for (int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(j%2) a[i][j]=cnt[k++];
			else a[n-i+1][j]=cnt[k++];
		}
	}
	for (int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==ans) cout<<j<<" "<<i;
		}
	}
	return 0;
}