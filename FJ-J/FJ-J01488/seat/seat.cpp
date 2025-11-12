#include <bits/stdc++.h>
using namespace std;
int n,m,seat[105],R;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>seat[i];
	R=seat[1];
	sort(seat+1,seat+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(R==seat[i]){
			R=i;
			break;
		}
	}
	cout<<(R-1)/n+1<<' ';
	int t=(R-1)%(2*n)+1;
	if(t>n) cout<<2*n-t+1;
	else cout<<t;
	return 0;
}
