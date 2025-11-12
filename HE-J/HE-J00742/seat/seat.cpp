#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+10];
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1],x=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			x=i;
			break;
		}
	}
	int x1=x,y=0;
	if(x%n==0) x/=n;
	else x=x/n+1;
	if(x%2!=0)y=x1%n;
	else y=x1%n+1;
	if(y==0) y=n;
	cout<<x<<" "<<y;
	return 0;
}

