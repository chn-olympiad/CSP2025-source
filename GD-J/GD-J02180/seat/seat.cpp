#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans1,ans2,a;
	cin>>n>>m;
	cin>>a;
	int cnt=1;
	for(int i=1;i<=n*m-1;i++){
		int b;cin>>b;
		if(b>a)cnt++;
	}
	if(cnt%n!=0){
		ans1=cnt/n+1;
	}else ans1=cnt/n;
	int t=ans1-1;
	if(ans1%2==1){
		ans2=cnt-t*n;
	}else{
		ans2=m-(cnt-t*n)+1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
