#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],cntx=1,cnty,mb;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	mb=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		cnty++;
		if(cnty>n){
			cnty=1;
			cntx++;
		}
		if(a[i]==mb){
			cout<<cntx<<' '<<cnty<<'\n';
			return 0;
		}
	}
	return 0;
} 