#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int r,sr,ans1,ans2;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
		if(i==0) r=a[i];
	}
	sort(a,a+m*n);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==r) sr=m*n-i;
	}
	if(sr%n==0){
	ans2=n;
	ans1=sr/n;
	}	
	else if((sr/n)%2==0){
		ans2=sr%n;
		ans1=sr/n+1;
	}	
	else if((sr/n)%2==1){
		ans2=n-sr%n+1;
		ans1=sr/n+1;
	}
	cout << ans1 << " " << ans2;
	
	
	return 0;
}
