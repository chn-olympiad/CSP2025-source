#include<bits/stdc++.h>
using namespace std;
int a[110],n,m;
int tot=1;
void solve(){
	cin>>n>>m;
	int r=n*m;
	cin>>a[1];
	for(int i=2;i<=r;i++){
		cin>>a[i];
		if(a[i]>a[1]) tot++;
	}
	int jishu=ceil(tot*1.0/n);
	cout<<jishu<<" ";
	if(jishu%2==1){
		if(tot%n) cout<<tot%n;
		else cout<<n;
	}else{
		if(tot%n) cout<<n-tot%n+1;
		else cout<<1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	return 0;
}

