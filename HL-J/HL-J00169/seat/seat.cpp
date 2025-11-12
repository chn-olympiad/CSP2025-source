
#include<bits/stdc++.h>
using namespace std;
int m,n,x,y;
int a[110];
int main(){
	//11111111111
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int llg;
	cin>>llg;
	a[0]=llg;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,greater<int>());
	for(int i=0;i<n*m;i++){
		if(a[i]==llg){
			llg=i+1;
			break;
		}
	}
	//cout<<llg;
	if(llg%n==0){
		x=llg/n;
		if(x%2==0){
			y=1;
		}else y=n;
	}else{
		x=llg/n+1;
		if(x%2==0){
			y=n-(llg%n)+1;
		}else y=llg%n;
	}
	cout<<x<<' '<<y;
	return 0;
}
