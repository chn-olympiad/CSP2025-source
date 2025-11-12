#include <iostream>
#include <algorithm>
using namespace std;

int a[225]={};

bool cmp(int a,int b){
	return a>b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			ans=i;
			break;
		}
	}
	int x=(ans+n-1)/n;
	int y=ans%n;
	if(y==0) y=n;
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
