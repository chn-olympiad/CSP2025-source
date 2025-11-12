#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1],d=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			d=n*m-i+1;
			break;
		}
	}
	int x=d/2;
	int xx=x%2;
	int ansx=x;
	int ansy;
	if(xx==1) ansy=d%(2*n);
	else ansy=n-(d%(2*n));
	cout<<ansx<<' '<<ansy;
	return 0;
} 
