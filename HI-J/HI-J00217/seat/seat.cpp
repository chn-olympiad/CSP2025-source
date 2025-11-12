#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,cnt,a;
int main(){
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	m*=n;
	for(int i=1;i<=m;i++){
		ll ci;
		cin>>ci;
		if(i==1){
			a=ci;
		}
		if(ci>a){
			cnt++;
		}
	}
	//cout<<cnt<<endl;
	cout<<cnt/n+1<<' ';
	if((cnt/n)%2==0){
		cout<<cnt%n+1;
	}
	else{
		cout<<n-cnt%n;
	}
	return 0;
}

