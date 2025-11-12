#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],s,c,r;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::ios::sync_with_stdio(true);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			s=i;
			break;
		}
	}
	if(s==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(s%n==0){
		c=s/n;
		if(c%2==0) r=1;
		else r=n;
		cout<<c<<" "<<r;
		return 0;
	}
	int x=(s-s%n)/n;
	if(x%2==0){
		r=s%n;
		c=x+1;
		cout<<c<<" "<<r; 
	}else{
		c=x+1;
		r=n-(s%n)+1;
		cout<<c<<" "<<r;
	}
	return 0;
}

