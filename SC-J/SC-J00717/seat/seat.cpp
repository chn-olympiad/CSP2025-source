#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	int a1;
	cin>>a1;
	int k=1;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(x>a1){
			k++;
		}
	}
	int lie=(k-1)/n+1;
	int hang;
	if(lie%2==1){
		hang=k%n;
		if(hang==0){
			hang=n;
		}
	}else{
		hang=n-k%n+1;
	}
	cout<<lie<<' '<<hang<<'\n';
	return 0;
}