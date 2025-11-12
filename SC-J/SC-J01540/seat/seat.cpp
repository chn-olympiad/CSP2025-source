#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
int a[MAXN];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) ans=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[cnt]==ans) cout<<i<<" "<<j;
				cnt++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[cnt]==ans) cout<<i<<" "<<j;
				cnt++;
			}
		}
	}
	return 0;
}