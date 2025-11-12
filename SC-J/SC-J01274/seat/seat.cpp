#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int val=a[1];
	int x,y;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==val){
			int j=n*m-i+1;
			x=j/n;
			y=j%m;
			if(j%n==0) x--;
			x++;
			if(y==0) y=m;
			if(x%2)	cout<<x<<" "<<y;
			else{
				cout<<x<<" "<<1+m-y;
			} 
			return 0;
		}
	}
	return 0;
} 