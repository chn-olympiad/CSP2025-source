#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],d,x,y;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		d=a[1];
	}
	if(n*m==1){
		cout<<d;
		return 0;
	}
	sort(a+1+n*m,a+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			x=i/n;
			if(i%n==0){
				y=n;
			}
			else{
				y=i%n;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
