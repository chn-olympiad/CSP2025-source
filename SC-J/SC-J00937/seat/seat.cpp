#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans1,a[10005],s;
bool aaa(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	ans1=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,aaa);
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j]==ans1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		else for(int j=n;j>=1;j--)if(a[(i-1)*n+j]==ans1){
			cout<<i<<" "<<(n-j+1);
			return 0;
		}
	}
	return 0;
}