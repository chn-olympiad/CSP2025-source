#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			b=i;
			break;
		}
	}
	int x=(b-1)/n+1,y=(b-1)%n+1;
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<" "<<y;
	return 0;
}