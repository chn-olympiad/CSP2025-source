#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=1,a1,temp;
	cin>>n>>m;
	cin>>a1;
	for(int i=1;i<n*m;i++){
		cin>>temp;
		if(temp>a1){
			ans++;
		}
	}
	int col=0,lin=0;
	col= (ans-1)/n +1;
	lin= (ans-1)%n+1;
	if(col % 2 ==0){
		lin = m+1 - lin;
	}
	cout<<col<<' '<<lin;
	
	return 0;
}
