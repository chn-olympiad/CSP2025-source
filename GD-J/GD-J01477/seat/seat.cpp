#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[400];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int fl=a[1],fla=-1;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==fl) fla=n*m-i+1;
	}
	int c=fla/m+(fla%m!=0);
	int r=fla%m;
	if(r==0) r+=m;
	if(c%2==0) r=n+1-r;
	
	cout<<c<<' '<<r;
	return 0;
}
