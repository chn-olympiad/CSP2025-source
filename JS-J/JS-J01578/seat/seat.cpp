#include<bits/stdc++.h>
using namespace std;
int s=1;
int n,m;
int a[10001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i>1&&a[i]>a[1]){
			s++;
		}
	}
	int x,y;
	if(s%n==0){
		x=s/n;
		y=n;
	}else{
		x=s/n+1;
		y=s%n;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
