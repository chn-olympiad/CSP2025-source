#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int cnt=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			cnt++;
		} 
	}
	if(cnt%n==0){
		if((cnt/n)%2==0){
			cout<<(cnt/n)<<" "<<1;
		}else{
			cout<<(cnt/n)<<" "<<n;
		}
	}else{
		if((cnt/n+1)%2==0){
			cout<<(cnt/n+1)<<" "<<n-cnt%n+1;
		}else{
			cout<<(cnt/n+1)<<" "<<cnt%n;
		}
	}
	return 0;
}
