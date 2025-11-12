#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m,mi,id;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	mi=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==mi){
			id=i;
			break;
		}
	}
	if(id<=n){
		if(id%n==0)
			cout<<1<<" "<<n;
		else
			cout<<1<<" "<<id%n;
	}
	else if(id>n){
		if(id%n==0){
			if(id/n%2==0)
				cout<<id/n<<" "<<1;
			else
				cout<<id/n<<" "<<n;
		}
		else{
			if((id/n+1)%2==0)
				cout<<id/n+1<<" "<<n+1-id%n;
			else
				cout<<id/n+1<<" "<<id%n;
		}
	}
	return 0;
}
