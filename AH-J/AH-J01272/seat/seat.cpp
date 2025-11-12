#include "bits/stdc++.h"
using namespace std;
int a[1005],t[1005][1005];
bool cmp(int p1,int p2){
	return p1>p2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k,ans=1;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];	
	sort(a+1,a+n*m+1,cmp);
	for (int i=2;i<=m;i+=2){
		for (int j=1;j<=n;j++){
			t[j][i-1]=a[ans];
			ans++;
		}
		for (int j=n;j>0;j--){
			t[j][i]=a[ans];
			ans++;
		}
	}
	if (m%2==1){
		for (int j=1;j<=n;j++){
			t[j][m]=a[ans];
			ans++;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if(t[i][j]==k){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
