#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],c,r,ans,ii;
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		ii++;
		if(b==a[i]) ans=ii;
	}
	c=ans/n;
	r=ans%n;
	cout<<c<<" ";
	if(c%2==0){
		cout<<r;
	}
	else{
		if(r==0){
			cout<<ans;
		}
		else cout<<r;
	}
	return 0;
} 
