#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],ans;
int main(){
	freopen("seat.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cu=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==cu){
			ans=n*m-i+1;
			break;
		}
	}
	int x,y;
	x=ans/n+1;
	y=ans%n;
	if(y==0){
		x--;
		y=n;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<" "<<y;
	freopen("seat.out","w",stdout);
	return 0;
}
