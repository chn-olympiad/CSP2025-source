#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,a[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(t==a[i]){
			t=i;
			break;
		}
	}
	int x=t%n;
	int y=(t-1)/n;
	if((y+1)%2==0){
		if(!x) x=1;
		cout<<y+1<<" "<<n-x+1;
	}else{
		if(!x)	x=n;
		cout<<y+1<<" "<<x;
	}
	return 0;
}
