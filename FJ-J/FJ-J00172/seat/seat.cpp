#include <bits/stdc++.h>
using namespace std;
int a[105],cnt,ans,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]) cnt++;
	}
	if(cnt%n==0) ans=cnt/n;
	else ans=cnt/n+1;
	if(ans%2==0){
		if(cnt%n==0) sum=1;
		else sum=n-cnt%n+1;
	}
	else{
		if(cnt%n==0) sum=n;
		else sum=cnt%n;	
	}
	cout<<ans<<" "<<sum;
	return 0;
}
