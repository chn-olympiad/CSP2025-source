#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],cnt;
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	if((cnt/n+1)%2==1){
		cout<<cnt/n+1<<" " <<cnt%n+1;
	}else{
		cout<<cnt/n+1<<" "<<m-cnt%n;
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	return 0;
}

