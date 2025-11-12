#include<bits/stdc++.h>
using namespace std;
int n,m,c[105],cnt = 1;
int cmp(int a,int b){
	return a>b;
}
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m; i++){
		cin>>c[i];
		if(c[i] > c[1]){
			cnt++;
		}
	}
	if(cnt%n == 0){
		cout<<cnt/n<<' ';
		if((cnt/n)%2 != 0){
			cout<<n;
		}
		else{
			cout<<1;
		}
	}else{
		cout<<cnt/n+1<<' ';
		if((cnt/n+1)%2 != 0){
			cout<<cnt%n;
		}
		else{
			cout<<n-cnt%n+1;
		}
	}
	return 0;
}
