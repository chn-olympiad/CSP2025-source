#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll seat;
ll heng,zong;
ll a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	seat=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==seat){
			seat=n*m-i+1;
			break;
		}
	}
	heng=ceil((double)seat/n);
	zong=(seat-1)%n+1;
	cout<<heng<<" ";
	if(heng%2==0){
		cout<<n-zong+1;
	}else{
		cout<<zong;
	}
	return 0;
}
