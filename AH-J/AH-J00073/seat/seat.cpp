#include<bits/stdc++.h>
using namespace std;
int a[205];
bool cmp(int x,int y){
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b==a[i]){
			b=i;
			break;
		}
	}
	int x,y;
	if(b%n==0) x=b/n;
	else x=b/n+1;
	if(b%m==0) y=m;
	else y=b%m;
	cout<<x<<" "<<y;
	return 0;
}
