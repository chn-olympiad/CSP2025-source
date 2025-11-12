#include<bits/stdc++.h>
using namespace std;
int n,m,sc,id;
int x,y;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sc=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==sc){
			id=i;
			break;
		}
	}
	if(id%n==0){
		y=id/n;
		if(y&1) x=n;
		else x=1;
		cout<<y<<" "<<x;
		return 0;
	}
	y=id/n+1;
	if(y&1==1) x=id%n;
	else x=n-(id%n)+1;
	cout<<y<<" "<<x;
	return 0;
}
/*2 2
99 100 97 98

 2 2
98 99 100 97*/