#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=0,b;
	b=a[1];
	int d;
	for(int i=1;i<b;i++){
		for(int j=1;j<=b;j++){
			if(a[j]<a[j+1]){
				d=a[j];
				a[j]=a[j+1];
				a[j+1]=d;
			}
		}
	}	
	for(int i=1;i<=n*m;i++){
		ans++;
		if(a[i]==b){
			break;
		}
	}
	if(ans%n==0){
		c=ans/n;
	}
	else{
		c=ans/n+1;
	}
	if(c==1){
		r=ans;
	}
	else if(c%2==0){
		r=n-ans%n+1;
	}
	else {
		r=ans%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
