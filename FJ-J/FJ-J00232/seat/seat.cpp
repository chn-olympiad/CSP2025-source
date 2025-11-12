#include <bits/stdc++.h>
using namespace std;
int n,m,a[205];
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int num=a[1],cnt=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		cnt++;
		if(a[i]==num) break;
	}
	if(cnt%n!=0) c=floor(cnt/n)+1;
	else c=cnt/n;
	if(c%2==1){
		if(cnt%n==0) r=n;
		else r=cnt%n;
	}
	else{
		if(cnt%n==0) r=1;
		else r=n-cnt%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
} 
