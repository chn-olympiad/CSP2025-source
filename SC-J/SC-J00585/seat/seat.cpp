#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m,ni=1,nj=1,a[N],mb,fla=1,no=1;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	mb=a[1];
	sort(a+1,a+1+n*m,cmp);
	while(no<=n*m){
		if(a[no]==mb){
			cout<<nj<<" "<<ni;
			return 0;
		}
		no++;
		ni+=fla;
		if(ni>n){
			ni=n;
			nj++;
			fla=-1;
		}
		if(ni<1){
			ni=1;
			nj++;
			fla=1;
		}
	}
	return 0;
} 