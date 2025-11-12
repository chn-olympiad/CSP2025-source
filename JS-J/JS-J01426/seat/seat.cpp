#include<bits/stdc++.h>
using namespace std;
int n=1,m=1,a[110],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]) cnt++;
	}
	if(cnt%n==0){
		if((cnt/n)%2==1) cout<<cnt/n<<' '<<n;
		else cout<<cnt/n<<' '<<'1';
	}
	else{
		if((cnt/n)%2==1) cout<<cnt/n+1<<' '<<n-cnt%n+1;
		else cout<<cnt/n+1<<' '<<cnt%n;
	}
	return 0;
}
