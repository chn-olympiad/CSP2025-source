#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105],R,num,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>R;
	b[1]=R;
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
	}sort(b+1,b+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(b[i]==R){
			num=n*m-i+1;
		}
	}if(num%n!=0)x=(num+n)/n;
	else x=num/n;
	cout<<x<<' ';
	if(num%n!=0)y=num%n;
	else y=n;
	if(x%2==1)cout<<y;
	else cout<<n-y+1;
	return 0;
}
	
