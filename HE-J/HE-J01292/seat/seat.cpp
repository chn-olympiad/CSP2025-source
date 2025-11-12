#include <bits/stdc++.h>
using namespace std;
int n,m;
int s,k,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++){
		cin>>k;
		if(k>s) cnt++;
	}
	cout<<cnt/m+1<<' ';
	if(cnt/n%2==0){
		cout<<cnt%m+1;
	}
	else{
		cout<<m-cnt%m;
	}
	return 0;
}
