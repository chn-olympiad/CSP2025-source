#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R_grade=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])R_grade++;
	}
	int k=(R_grade-1)%(2*n)+1;
	cout<<(R_grade+n-1)/n<<" ";
	if(k>n)cout<<2*n-k+1;
	else cout<<k;
	return 0;
}