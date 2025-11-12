#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,position,chu,yu;
bool compare(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m+1,compare);
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			position=i+1;
			break;
		}
	}
	chu=position/n;
	yu=position%n;
	if(yu>0){
		cout<<chu+1<<" ";
		int y=chu+1;
		if(y%2==1){
			if(position<=n) cout<<position;
			else cout<<position%n;
		}
		else{
			cout<<n+1-yu;
		}
		
	}
	else{
		cout<<chu<<" ";
		if(chu%2==1) cout<<n;
		else cout<<1;
	}
	
	
	return 0;
}
