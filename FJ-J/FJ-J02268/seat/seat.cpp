#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	priority_queue<int> as;
	int a;
	cin>>a;
	as.push(a);
	for(int i=1;i<n*m;i++){
		int c;
		cin>>c;
		as.push(c);
	}
	int b;
	for(int i=1;i<=n*m;i++){
		if(as.top()==a){
			b=i;
			break;
		}
		as.pop();
	}
	int x,y;
	if(b%n==0){
		y=b/n;
		if(y%2==0){
			x=1;
		}else{
			x=n;
		}
	}else{
		y=b/n+1;
		if(y%2==0){
			x=n-b%n+1;
		}else{
			x=b%n;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}