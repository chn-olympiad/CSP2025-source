#include<bits/stdc++.h>
using namespace std;
int m,n,a[10001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++) scanf("%d",&a[i]);
	int k=a[1];
	sort(a+1,a+m*n+1);
	for(int i=m*n;i>=1;i--){
		if(k==a[i]) k=i;
	}
	k=(m*n-k+1);
	int c=k/n,r;
	if(k%n==0) cout<<c<<" ";
	else {
		cout<<c+1;
		c+=1;
	}
	if(c%2==1){
		if(k%n==0) r=n;
		else r=k%n;
	}
	else{
		if(k%n==0) r=1;
		else r=n-k%n;
	}
	cout<<r;
	return 0;
} 
