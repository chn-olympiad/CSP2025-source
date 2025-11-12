#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[106]={},x,y;
	cin>>n>>m;
	for(int i=1;i<n*m+1;i++){
		cin>>a[i];
	}
	int score=a[1],k;
	sort(a+1,a+m*n+1);
	for(int i=1;i<n*m+1;i++){
		if(a[i]==score){
			k=i;
			break;
		}
	}
	k=n*m-k+1;
	y=(k-1)/n+1;
	if(y%2==0){
		x=n-(k%n)+1;
		if(k%n==0)x-=n;
	}else{
		x=k%n;
		if(k%n==0)x+=n;
	}
	cout<<y<<' '<<x;
	return 0;
}
