#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+1+n*m);
	int cnt=0;
	for(int i=n*m;i>=1;i--){
		if(a[i]==ans){
			cnt=n*m-i+1;
			break;
		}
	}
	int sum=cnt/m;
	int c=0,r=0;
	if(cnt%m==0&&sum%2==0){
		c=sum;
		r=1;
	}
	else if(cnt%m==0&&sum%2!=0){
		c=sum;
		r=n;
	}
	else if(cnt%m!=0&&sum%2==0){
		c=sum+1;
		r=cnt%m;
	}
	else if(cnt%m!=0&&sum%2!=0){
		c=sum+1;
		int s=cnt%m;
		r=n-s+1;
	}
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<c<<" "<<r;
	return 0;
}


